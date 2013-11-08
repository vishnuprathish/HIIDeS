
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


// Added Header files for daemonizing
#include <sys/wait.h>
#include <unistd.h>

#include "read_buffer.c"

/*Included Files*/
#include "packet_processor.c"
//#include "stdf_convert.c"

/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 1518

/* ethernet headers are always exactly 14 bytes [1] */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN	6


int main(int argc, char **argv)
{


	  int pid;   //Process ID


	 if ((pid=fork()) < 0)
	      {
	        perror ("Fork failed");
	        exit(errno);
	      }
	 if (pid>0) exit(0);
	{
	// Now main f/n is a daemon
	int rpid;
	 if ((rpid=fork()) < 0)
	      {
	        perror ("read fork failed");
	        exit(errno);
	      }
	 if (rpid>0) 
	{
	
	//fp3=fopen("buffer.dat","a+");

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
	//fclose(fp3);
	//return 0;

	}			//Daemon end
	if(rpid==0)
	{
			read_buffer();			//daemonized the child
	}
	}
}

