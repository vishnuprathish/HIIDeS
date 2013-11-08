
#define APP_NAME		"HIIDeS"
#define APP_DESC		"Hybrid Intelligent Intrusion Detection System	"
#define APP_COPYRIGHT	"Copy right or copyleft, we dont care... ;)"
#define APP_DISCLAIMER	"THERE IS ABSOLUTELY NO WARRANTY FOR THIS PROGRAM."

#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
/*Included Files*/

#include "stdf_convert.c"
/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 1518

/* ethernet headers are always exactly 14 bytes [1] */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN	6


FILE *fp3;
char temp[8][100];
/* Ethernet header */
struct sniff_ethernet {
        u_char  ether_dhost[ETHER_ADDR_LEN];    /* destination host address */
        u_char  ether_shost[ETHER_ADDR_LEN];    /* source host address */
        u_short ether_type;                     /* IP? ARP? RARP? etc */
};

/* IP header */
struct sniff_ip {
        u_char  ip_vhl;                 /* version << 4 | header length >> 2 */
        u_char  ip_tos;                 /* type of service */
        u_short ip_len;                 /* total length */
        u_short ip_id;                  /* identification */
        u_short ip_off;                 /* fragment offset field */
        #define IP_RF 0x8000            /* reserved fragment flag */
        #define IP_DF 0x4000            /* dont fragment flag */
        #define IP_MF 0x2000            /* more fragments flag */
        #define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
        u_char  ip_ttl;                 /* time to live */
        u_char  ip_p;                   /* protocol */
        u_short ip_sum;                 /* checksum */
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
};
#define IP_HL(ip)               (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)                (((ip)->ip_vhl) >> 4)

/* TCP header */
typedef u_int tcp_seq;

struct sniff_tcp {
        u_short th_sport;               /* source port */
        u_short th_dport;               /* destination port */
        tcp_seq th_seq;                 /* sequence number */
        tcp_seq th_ack;                 /* acknowledgement number */
        u_char  th_offx2;               /* data offset, rsvd */
#define TH_OFF(th)      (((th)->th_offx2 & 0xf0) >> 4)
        u_char  th_flags;
        #define TH_FIN  0x01
        #define TH_SYN  0x02
        #define TH_RST  0x04
        #define TH_PUSH 0x08
        #define TH_ACK  0x10
        #define TH_URG  0x20
        #define TH_ECE  0x40
        #define TH_CWR  0x80
        #define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
        u_short th_win;                 /* window */
        u_short th_sum;                 /* checksum */
        u_short th_urp;                 /* urgent pointer */
};

//Structure representing a TCP connection
struct connection
{
	unsigned int noofbytes[2];
	struct in_addr srcip,destip;
	u_short srcport,destport;
	struct connection *next;
	time_t starttime,endtime;
	int duration;
	int flag;
}*c,*ptr,*first=NULL;

//Connections are maintained as a linked list. 
// to insert into the list
void insertconnection(struct connection *c)
{
	if(first==NULL)
		first=c;
	else
	{
		for(ptr=first;ptr->next!=NULL;ptr=ptr->next);
		ptr->next=c;
			
	}	
	c->next=NULL;	
}

//delete a connection from the linked list
void deleteconnection(struct connection *c)
{
	for(ptr=first;ptr->next!=c;ptr=ptr->next);
	ptr->next=c->next;
	free(c);
}

//Function prototypes
void
got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

void
print_payload(const u_char *payload, int len);

void
print_hex_ascii_line(const u_char *payload, int len, int offset);


/*
 * print data in rows of 16 bytes: offset   hex   ascii
 *
 * 00000   47 45 54 20 2f 20 48 54  54 50 2f 31 2e 31 0d 0a   GET / HTTP/1.1..
 */
void
print_hex_ascii_line(const u_char *payload, int len, int offset)
{

	int i;
	int gap;
	const u_char *ch;

	/* offset */
	printf("%05d   ", offset);
	
	/* hex */
	ch = payload;
	for(i = 0; i < len; i++) {
		printf("%02x ", *ch);
		ch++;
		/* print extra space after 8th byte for visual aid */
		if (i == 7)
			printf(" ");
	}
	/* print space to handle line less than 8 bytes */
	if (len < 8)
		printf(" ");
	
	/* fill hex gap with spaces if not full line */
	if (len < 16) {
		gap = 16 - len;
		for (i = 0; i < gap; i++) {
			printf("   ");
		}
	}
	printf("   ");
	
	/* ascii (if printable) */
	ch = payload;
	for(i = 0; i < len; i++) {
		if (isprint(*ch))
			printf("%c", *ch);
		else
			printf(".");
		ch++;
	}

	printf("\n");

return;
}

/*
 * print packet payload data (avoid printing binary data)
 */
void
print_payload(const u_char *payload, int len)
{

	int len_rem = len;
	int line_width = 16;			/* number of bytes per line */
	int line_len;
	int offset = 0;					/* zero-based offset counter */
	const u_char *ch = payload;

	if (len <= 0)
		return;

	/* data fits on one line */
	if (len <= line_width) {
		print_hex_ascii_line(ch, len, offset);
		return;
	}

	/* data spans multiple lines */
	for ( ;; ) {
		/* compute current line length */
		line_len = line_width % len_rem;
		/* print line */
		print_hex_ascii_line(ch, line_len, offset);
		/* compute total remaining */
		len_rem = len_rem - line_len;
		/* shift pointer to remaining bytes to print */
		ch = ch + line_len;
		/* add offset */
		offset = offset + line_width;
		/* check if we have line width chars or less */
		if (len_rem <= line_width) {
			/* print last line and get out */
			print_hex_ascii_line(ch, len_rem, offset);
			break;
		}
	}

return;
}

/*
 * dissect/print packet
 */
void
got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
      
	static int count = 1;                   /* packet counter */
	
	/* declare pointers to packet headers */
	const struct sniff_ethernet *ethernet;  /* The ethernet header [1] */
	const struct sniff_ip *ip;              /* The IP header */
	const struct sniff_tcp *tcp;            /* The TCP header */
	const char *payload;                    /* Packet payload */

	int size_ip;
	int size_tcp;
	int size_payload;
	
	//printf("\nPacket number %d:\n", count);
	count++;
	
	/* define ethernet header */
	ethernet = (struct sniff_ethernet*)(packet);
	
	/* define/compute ip header offset */
	ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
	size_ip = IP_HL(ip)*4;
	if (size_ip < 20) {
		printf("   * Invalid IP header length: %u bytes\n", size_ip);
		return;
	}
		
		/*
	 *  OK, this packet is TCP.
	 */
	
	/* define/compute tcp header offset */
	
	
	tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
	size_tcp = TH_OFF(tcp)*4;
	if (size_tcp < 20) {
		printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
		return;
	}
	
	//printf("   Src port: %d\n", ntohs(tcp->th_sport));
	//printf("   Dst port: %d\n", ntohs(tcp->th_dport));
	
	if(tcp->th_flags == 2)					//SYN Packet - Start of connection
	{
		//printf("\tSYN signal\n"); 
		c=(struct connection*)malloc(sizeof(struct connection));
		c->srcip=ip->ip_src;
		c->destip=ip->ip_dst;
		c->srcport=tcp->th_sport;
		c->destport=tcp->th_dport;
		c->noofbytes[0]=0;
		c->noofbytes[1]=0;
		c->duration=0;
		c->flag=-1;
		time(&(c->starttime));
		insertconnection(c);    
		
		
	}		
	else if((tcp->th_flags & TH_FIN) == 1)				//FIN packet detected  -rewrite the code . Track tcp connection properly
	{    
			
		ptr=first;
		while(ptr!=NULL)
		{
			if(ptr->srcip.s_addr==ip->ip_src.s_addr &&  ptr->destip.s_addr==ip->ip_dst.s_addr && 
			 ptr->srcport==tcp->th_sport && ptr->destport==tcp->th_dport)
			{
				ptr->noofbytes[0]+=20;
			 	
			 	ptr->flag++;
			 	break;
			}
			else if(ptr->srcip.s_addr==ip->ip_dst.s_addr &&  ptr->destip.s_addr==ip->ip_src.s_addr &&
			 ptr->srcport==tcp->th_dport && ptr->destport==tcp->th_sport)
			{
				ptr->noofbytes[1]+=20;

				ptr->flag++;
			 	break;
			}
			else
				ptr=ptr->next;    
		}
		if(ptr->flag==1)
		{
			time(&(ptr->endtime));    
			ptr->duration=(int)(ptr->endtime-ptr->starttime);
			//printf("\tFIN\n");
			printf("no of bytes down:%u\n",ptr->noofbytes[1]);
			printf("no of bytes up:%u\n",ptr->noofbytes[0]);
			printf("duration of time:%u\n",ptr->duration);
			printf("Src Ip:%s\n",inet_ntoa(ptr->srcip));
			printf("Dst Ip:%s\n",inet_ntoa(ptr->destip));
			printf("Src Port:%d \n",ntohs(ptr->srcport));
			printf("dest Port:%d \n",ntohs(ptr->destport));
			printf("------------------\n",sizeof(u_short),sizeof(int));
			
			//compare_rules\\(stdfip(inet_ntoa(ptr->srcip)),stdfip(inet_ntoa(ptr->destip)),stdfp(ntohs(ptr->srcport)),stdfp(ntohs(ptr->destport)),"1","1","1","1");//char dest_ip[13],char src_pno[6],char dest_pno[6],char duration[6],char protocol[2],char num_pso[11],char num_psr[11]);
            
			/* write to file*/
			//TCP protocol passed as 0
			strcpy(temp[0],stdfip(inet_ntoa(ptr->srcip)));
			strcpy(temp[1],stdfip(inet_ntoa(ptr->destip)));
			strcpy(temp[2],stdfp(ntohs(ptr->srcport)));
			strcpy(temp[3],stdfp(ntohs(ptr->destport)));
			strcpy(temp[4],stdfdur(ptr->duration));
			strcpy(temp[5],stdfnfb(ptr->noofbytes[0]));
			strcpy(temp[6],stdfnfb(ptr->noofbytes[1]));
			fprintf(fp3,"%s%s%s%s%s%s%s%s\n",temp[0],temp[1],temp[2],temp[3],temp[4],"0",temp[5],temp[6]);
            fclose(fp3);
			fp3=fopen("buffer.dat","a+");
		}	
		
	}
	//printf("\tsequence no:%u\n",tcp->th_seq);
	//printf("\tacknowledge no:%u\n",tcp->th_ack);
		
	/* define/compute tcp payload (segment) offset */
	payload = (u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
	
	/* compute tcp payload (segment) size */
	size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);
	
		
	ptr=first;
	while(ptr!=NULL)
	{
		if(ptr->srcip.s_addr==ip->ip_src.s_addr &&  ptr->destip.s_addr==ip->ip_dst.s_addr && 
		 ptr->srcport==tcp->th_sport && ptr->destport==tcp->th_dport)
		{
			ptr->noofbytes[0]+=20; 
			
			if (size_payload > 0) 
			{
				ptr->noofbytes[0]+=size_payload;		
			}
			break; 

		}
		else if(ptr->srcip.s_addr==ip->ip_dst.s_addr &&  ptr->destip.s_addr==ip->ip_src.s_addr &&
		 ptr->srcport==tcp->th_dport && ptr->destport==tcp->th_sport)
		{
			ptr->noofbytes[1]+=20;
			
			if (size_payload > 0) 
			{
				ptr->noofbytes[1]+=size_payload;		
			}
			break; 

		}		
		else
			ptr=ptr->next;	
	}        
	/*
	if (size_payload > 0) 
			{
				printf("   Pay-load (%d bytes):\n", size_payload);
				//print_payload(payload, size_payload);
			}
*/
return;
}

int main(int argc, char **argv)
{
	
	fp3=fopen("buffer.dat","a+");

	char *dev = NULL;			/* capture device name */
	char errbuf[PCAP_ERRBUF_SIZE];		/* error buffer */
	pcap_t *handle;				/* packet capture handle */

	char filter_exp[] = "tcp";		/* filter expression [3] */
	struct bpf_program fp;			/* compiled filter program (expression) */
	bpf_u_int32 mask;			/* subnet mask */  //barkeley packet format
	bpf_u_int32 net;			/* ip */
	int num_packets = -1;			/* number of packets to capture */

	
	/* the interface name to capture */
	dev="wlan0";
	
	/* get network number and mask associated with capture device */
	if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
		fprintf(stderr, "Couldn't get netmask for device %s: %s\n",
		    dev, errbuf);
		net = 0;
		mask = 0;
	}

	/* print capture info */
	printf("Packet sniffing interface: %s\n", dev);
	//printf("Number of packets: %d\n", num_packets);
	//printf("Filter expression: %s\n", filter_exp);

	/* open capture device */
	handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
		exit(EXIT_FAILURE);
	}

	/* make sure we're capturing on an Ethernet device [2] */
	if (pcap_datalink(handle) != DLT_EN10MB) {
		fprintf(stderr, "%s is not an Ethernet\n", dev);
		exit(EXIT_FAILURE);
	}

	/* compile the filter expression */
	if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
		fprintf(stderr, "Couldn't parse filter %s: %s\n",
		    filter_exp, pcap_geterr(handle));
		exit(EXIT_FAILURE);
	}

	/* apply the compiled filter */
	if (pcap_setfilter(handle, &fp) == -1) {
		fprintf(stderr, "Couldn't install filter %s: %s\n",
		    filter_exp, pcap_geterr(handle));
		exit(EXIT_FAILURE);
	}

	/* now we can set our callback function */
	pcap_loop(handle, num_packets, got_packet, NULL);

	/* cleanup */
	pcap_freecode(&fp);
	pcap_close(handle);

	printf("\nCapture complete.\n");
fclose(fp3);
return 0;
}

