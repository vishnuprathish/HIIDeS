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

struct connection
{
	int conid;
	unsigned int noofbytes[2];
	struct in_addr srcip,destip;
	u_short srcport,destport;
	struct connection *next;
	time_t starttime,endtime;
	int duration;
	int flag;
	tcp_seq seq,ack;
	
	
}*c,*ptr,*first=NULL;

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
void deleteconnection(int id)
{
	struct connection *con,*condel;
	if(first->conid==id)
	{
		free(first);
		first=NULL;
		return;
	}
	if(first->next!=NULL)
	{	
		for(con=first;(con->next)->conid!=id,con->next!=NULL;con=con->next);
		condel=con->next;
		if(condel!=NULL)
		{
			con->next=condel->next;
			free(condel);
		}
	}
}
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
	
		
	/* define ethernet header */
	ethernet = (struct sniff_ethernet*)(packet);
	
	/* define/compute ip header offset */
	ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
	size_ip = IP_HL(ip)*4;
	if (size_ip < 20) {
		printf("   * Invalid IP header length: %u bytes\n", size_ip);
		return;
	}
		
	/* determine protocol 	
	 */
	/*
	switch(ip->ip_p) {
		
		case IPPROTO_TCP:
			printf("   Protocol: TCP\n");
			break;
		case IPPROTO_UDP:
			printf("   Protocol: UDP\n");
			return;
		case IPPROTO_ICMP:
			printf("   Protocol: ICMP\n");
			return;
		case IPPROTO_IP:
			printf("   Protocol: IP\n");
			return;
		default:
			printf("   Protocol: unknown\n");
			return;
	}
	*/
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
	
	/* define/compute tcp payload (segment) offset */
		payload = (u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
		
		/* compute tcp payload (segment) size */
		size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);
		
	if(tcp->th_flags == 2)				//SYN signal
	{
		
		printf("\tSYN signal\n"); 
		c=(struct connection*)malloc(sizeof(struct connection));
		c->conid=count++;
		c->srcip=ip->ip_src;
		c->destip=ip->ip_dst;
		c->srcport=tcp->th_sport;
		c->destport=tcp->th_dport;
		//c->noofbytes[0]=0;
		c->noofbytes[1]=0;
		c->duration=0;
		c->seq=tcp->th_seq;
		c->ack=tcp->th_ack;
		c->flag=-1;
		time(&(c->starttime));
		c->noofbytes[0]=20; 
		insertconnection(c);    
		
		
	}
	else if(tcp->th_flags == 18)			//SYN-ACK signal
	{
		printf("\tSYN-ACK \n");	
		ptr=first;
		while(ptr!=NULL)
		{		
			if(ptr->srcip.s_addr==ip->ip_dst.s_addr &&  ptr->destip.s_addr==ip->ip_src.s_addr &&
				 ptr->srcport==tcp->th_dport && ptr->destport==tcp->th_sport)
				{
					ptr->noofbytes[1]+=20; 
			 		ptr->seq=tcp->th_seq;
			 		ptr->ack=tcp->th_ack;
			 		break;
				}
			else
				ptr=ptr->next;	
		}
		
	}
	else if(tcp->th_flags & TH_FIN == 1)			//FIN signal
	{    
		printf("\tFIN\n");	
		ptr=first;
		while(ptr!=NULL)
		{
			if(ptr->srcip.s_addr==ip->ip_src.s_addr &&  ptr->destip.s_addr==ip->ip_dst.s_addr &&
			 ptr->srcport==tcp->th_sport && ptr->destport==tcp->th_dport)
			{
				if(ptr->ack==tcp->th_seq||ptr->seq==tcp->th_seq)
				{
					ptr->seq=tcp->th_seq;
					ptr->ack=tcp->th_ack;
					ptr->noofbytes[0]+=20;
			 	 	ptr->flag++;
			 	 	printf("flag:%d",ptr->flag);
			 		
				}
				break;
			}
			else if(ptr->srcip.s_addr==ip->ip_dst.s_addr &&  ptr->destip.s_addr==ip->ip_src.s_addr &&
			 ptr->srcport==tcp->th_dport && ptr->destport==tcp->th_sport)
			{
				if(ptr->ack==tcp->th_seq||ptr->seq==tcp->th_seq)
				{
					ptr->seq=tcp->th_seq;
					ptr->ack=tcp->th_ack;
					ptr->noofbytes[1]+=20;
					ptr->flag++;
				 	printf("flag:%d",ptr->flag);
				}	
				break;
			}
			else
				ptr=ptr->next;    
		}
			
		
	}
	else
	{
		
		
	
		
		ptr=first;
		while(ptr!=NULL)
		{
					
			if(ptr->srcip.s_addr==ip->ip_src.s_addr &&  ptr->destip.s_addr==ip->ip_dst.s_addr && 
			 ptr->srcport==tcp->th_sport && ptr->destport==tcp->th_dport)
			{
				
				if(ptr->seq==tcp->th_seq)		
				{
					
					ptr->noofbytes[0]+=20; 
					if (size_payload > 0) 
					{
						ptr->noofbytes[0]+=size_payload;		
					}
				} 
				else if(ptr->ack==tcp->th_seq) 
				{
					ptr->seq=tcp->th_seq;
					ptr->ack=tcp->th_ack;
					ptr->noofbytes[0]+=20; 
				
					if (size_payload > 0) 
					{
						ptr->noofbytes[0]+=size_payload;		
					}
						
					
				}
				if(ptr->flag==1)
					{
						time(&(ptr->endtime));    
						ptr->duration=(int)(ptr->endtime-ptr->starttime);
						printf("\ncon no:%d\n",ptr->conid);
						printf("duration of time:%u\n",ptr->duration);
						printf("no of bytes up:%u\n",ptr->noofbytes[0]);
						printf("no of bytes down:%u\n",ptr->noofbytes[1]);
						printf("ip address1:%s\n",inet_ntoa(ptr->srcip));
						printf("ip address2:%s\n",inet_ntoa(ptr->destip));
						printf("port addresses:%d\t%d\n",ntohs(ptr->srcport),ntohs(ptr->destport));
						deleteconnection(ptr->conid);
						/* write to file*/
			//TCP protocol passed as 0
			strcpy(temp[0],stdfip(inet_ntoa(ptr->srcip)));
			strcpy(temp[1],stdfip(inet_ntoa(ptr->destip)));
			strcpy(temp[2],stdfp(ntohs(ptr->srcport)));
			strcpy(temp[3],stdfp(ntohs(ptr->destport)));
			strcpy(temp[4],stdfdur(ptr->duration));
			strcpy(temp[5],stdfnfb(ptr->noofbytes[0]));
			strcpy(temp[6],stdfnfb(ptr->noofbytes[1]));
			fp3=fopen("buffer.dat","a+");
			fprintf(fp3,"%s%s%s%s%s%s%s%s\n",temp[0],temp[1],temp[2],temp[3],temp[4],"0",temp[5],temp[6]);
            fclose(fp3);
			
			
					}
				break;

			}
			else if(ptr->srcip.s_addr==ip->ip_dst.s_addr &&  ptr->destip.s_addr==ip->ip_src.s_addr &&
			 ptr->srcport==tcp->th_dport && ptr->destport==tcp->th_sport)
			{
				
				if(ptr->seq==tcp->th_seq)			//16 means ACK  -------tcp->th_flags != 16 && 
				{
					ptr->noofbytes[1]+=20; 
				
					if (size_payload > 0) 
					{
						ptr->noofbytes[1]+=size_payload;		
					}
				}  
				else if(ptr->ack==tcp->th_seq)
				{
				
					ptr->seq=tcp->th_seq;
					ptr->ack=tcp->th_ack;
					ptr->noofbytes[1]+=20;
			
					if (size_payload > 0) 
					{
						ptr->noofbytes[1]+=size_payload;		
					}
										 
				}
				if(ptr->flag==1)
					{
						time(&(ptr->endtime));    
						ptr->duration=(int)(ptr->endtime-ptr->starttime);
						printf("\ncon no:%d\n",ptr->conid);
						printf("\nduration of time:%u\n",ptr->duration);
						printf("no of bytes up:%u\n",ptr->noofbytes[0]);
						printf("no of bytes down:%u\n",ptr->noofbytes[1]);
						printf("ip address1:%s\n",inet_ntoa(ptr->srcip));
						printf("ip address2:%s\n",inet_ntoa(ptr->destip));
						printf("port addresses:%d\t%d\n",ntohs(ptr->srcport),ntohs(ptr->destport));
						deleteconnection(ptr->conid);
						
						
									/* write to file*/
			//TCP protocol passed as 0
			strcpy(temp[0],stdfip(inet_ntoa(ptr->srcip)));
			strcpy(temp[1],stdfip(inet_ntoa(ptr->destip)));
			strcpy(temp[2],stdfp(ntohs(ptr->srcport)));
			strcpy(temp[3],stdfp(ntohs(ptr->destport)));
			strcpy(temp[4],stdfdur(ptr->duration));
			strcpy(temp[5],stdfnfb(ptr->noofbytes[0]));
			strcpy(temp[6],stdfnfb(ptr->noofbytes[1]));
			fp3=fopen("buffer.dat","a+");
			fprintf(fp3,"%s%s%s%s%s%s%s%s\n",temp[0],temp[1],temp[2],temp[3],temp[4],"0",temp[5],temp[6]);
            fclose(fp3);
		
			
			
					}	
				
				break;

			}		
			else
				ptr=ptr->next;	
		}   
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
