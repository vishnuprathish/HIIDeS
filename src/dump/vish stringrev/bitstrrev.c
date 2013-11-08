
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char subst[50];
FILE *fp2;

char * substring(int start, int stop, const char *text)
{
	int i,j;

	j=0;
	for(i=start-1;i<stop;i++)
	{
		subst[j++]=text[i];
	}	
	subst[j]='\0';
	return(subst);
}

void todec(int n)
{
	int a[20],i,count=0,b[20],c[20],sum=0;
	for (i=0;n>=1;i++)
	{
		a[i]=n%10;
		n=n/10; // Loop To reverse the number And put all reversed numbers in arry a[i]
		count=count + 1; // count to count the number of times this loop runs
	}
	for (i=0;i<=count-1;i++) // count -1 condition is used to run the loop till the previous loop run
	{
		b[i]=pow(2,i); // This is to raise the power of 2 to no of times previous loop runned.
	}
	for (i=0;i<=count-1;i++)
	{
		c[i]=a[i] * b[i]; // Multiply a[i] or reveresed binary no with b[i] or increasing pow of 2 to count-1
		sum=sum +c[i]; // it is to add the c[i] elements with each other n put into sum variable.
	}
		fprintf(fp2,"%d ,",sum);
}
		
		
const char *protosel(char *param)			//PROT
{
	if(strcmp("01",param)==0)
	{
		fprintf(fp2,"tcp ,");
	}
	else if(strcmp("10",param)==0)
	{
		fprintf(fp2,"udp ,");
	}
	else if(strcmp("11",param)==0)
	{
		fprintf(fp2,"icmp ,");
	}
	else 
	fprintf(fp2,"00 ,");
}


const char *servicetodec(char *param)					//service
{
	if(strcmp("00000001",param)==0)
	{
		fprintf(fp2,"auth ,");
	}
	else if(strcmp("00000010",param)==0)
	{
		fprintf(fp2,"bgp ,");
	}
	else if(strcmp("00000011",param)==0)
	{
		fprintf(fp2,"courier ,");
	}
	else if(strcmp("00000100",param)==0)
	{
		fprintf(fp2,"csnet_ns ,");
	}
	else if(strcmp("00000101",param)==0)
	{
		fprintf(fp2,"ctf ,");
	}
	else if(strcmp("00000110",param)==0)
	{
		fprintf(fp2,"daytime ,");
	}
	else if(strcmp("00000111",param)==0)
	{
		fprintf(fp2,"discard ,");
	}
	else if(strcmp("00001000",param)==0)
	{
		fprintf(fp2,"domain ,") ;
	}
	else if(strcmp("00001001",param)==0)
	{
		fprintf(fp2,"domain_u ,");
	}
	else if(strcmp("00001010",param)==0)
	{
		fprintf(fp2,"echo ,");
	}
	else if(strcmp("00001011",param)==0)
	{
		fprintf(fp2,"eco_i ,");
	}
	else if(strcmp("00001100",param)==0)
	{
		fprintf(fp2,"ecr_i ,");
	}
	else if(strcmp("00001101",param)==0)
	{
		fprintf(fp2,"efs ,");
	}
	else if(strcmp("00001110",param)==0)
	{
		fprintf(fp2,"exec ,");
	}
	
	else if(strcmp("00001111",param)==0)
	{
		fprintf(fp2,"finger ,");
	}
	else if(strcmp("00010000",param)==0)
	{
		fprintf(fp2,"ftp ,");
	}
	else if(strcmp("00010001",param)==0)
	{
		fprintf(fp2,"ftp_data ,") ;
	}
	else if(strcmp("00010010",param)==0)
	{
		fprintf(fp2,"gopher ,");
	}
	else if(strcmp("00010011",param)==0)
	{
		fprintf(fp2,"hostnames ,");
	}
	else if(strcmp("00010100",param)==0)
	{
		fprintf(fp2,"http ,");
	}
	else if(strcmp("00010101",param)==0)
	{
		fprintf(fp2,"http_443 ,");
	}
	else if(strcmp("00010110",param)==0)
	{
		fprintf(fp2,"imap4 ,");
	}
	else if(strcmp("00010111",param)==0)
	{
		fprintf(fp2,"IRC ,");
	}
	else if(strcmp("00011000",param)==0)
	{
		fprintf(fp2,"iso_tsap ,");
	}
	else if(strcmp("00011001",param)==0)
	{
		fprintf(fp2,"klogin ,");
	}
	else if(strcmp("00011010",param)==0)
	{
		fprintf(fp2,"kshell ,");
	}
	else if(strcmp("00011011",param)==0)
	{
		fprintf(fp2,"kdap ,");
	}
	else if(strcmp("00011100",param)==0)
	{
		fprintf(fp2,"link ,");
	}
	else if(strcmp("00011101",param)==0)
	{
		fprintf(fp2,"login ,");
	}
	else if(strcmp("00011110",param)==0)
	{
		fprintf(fp2,"mtp ,");
	}
	else if(strcmp("00011111",param)==0)
	{
		fprintf(fp2,"name ,");
	}
	else if(strcmp("00100000",param)==0)
	{
		fprintf(fp2,"netbios_dgm ,");
	}
	else if(strcmp("00100001",param)==0)
	{
		fprintf(fp2,"netbios_ns ,");
	}
	else if(strcmp("00100010",param)==0)
	{
		fprintf(fp2,"netbios_ssn ,");
	}
	else if(strcmp("00100011",param)==0)
	{
		fprintf(fp2,"netstat ,");
	}
	else if(strcmp("00100100",param)==0)
	{
		fprintf(fp2,"nnsp ,");
	}
	else if(strcmp("00100101",param)==0)
	{
		fprintf(fp2,"nntp ,");
	}
	else if(strcmp("00100110",param)==0)
	{
		fprintf(fp2,"ntp_u ,");
	}
	else if(strcmp("00100111",param)==0)
	{
		fprintf(fp2,"other ,");
	}
	else if(strcmp("00101000",param)==0)
	{
		fprintf(fp2,"pm_dump ,");
	}
	else if(strcmp("00101001",param)==0)
	{
		fprintf(fp2,"pop_2 ,");
	}
	else if(strcmp("00101010",param)==0)
	{
		fprintf(fp2,"pop_3 ,");
	}
	else if(strcmp("00101011",param)==0)
	{
		fprintf(fp2,"printer ,");
	}
	else if(strcmp("00101100",param)==0)
	{
		fprintf(fp2,"private ,");
	}
	else if(strcmp("00101101",param)==0)
	{
		fprintf(fp2,"red_i ,");
	}
	else if(strcmp("00101110",param)==0)
	{
		fprintf(fp2,"remote_job ,");
	}
	else if(strcmp("00101111",param)==0)
	{
		fprintf(fp2,"rje ,");
	}
	else if(strcmp("00110000",param)==0)
	{
		fprintf(fp2,"shell ,");
	}
	else if(strcmp("00110001",param)==0)
	{
		fprintf(fp2,"smtp ,");
	}
	else if(strcmp("00110010",param)==0)
	{
		fprintf(fp2,"sql_net ,");
	}
	else if(strcmp("ssh",param)==0)
	{
		fprintf(fp2,"ssh ,");
	}
	else if(strcmp("00110100",param)==0)
	{
		fprintf(fp2,"sunrpc ,");
	}
	else if(strcmp("00110100",param)==0)
	{
		fprintf(fp2,"supdup ,");
	}
	else if(strcmp("00110101",param)==0)
	{
		fprintf(fp2,"systat ,");
	}
	else if(strcmp("00110110",param)==0)
	{
		fprintf(fp2,"telnet ,");
	}
	else if(strcmp("00110111",param)==0)
	{
		fprintf(fp2,"tftp_u ,");
	}
	else if(strcmp("00111000",param)==0)
	{
		fprintf(fp2,"tim_i ,");
	}
	else if(strcmp("00111001",param)==0)
	{
		fprintf(fp2,"time ,");
	}
	else if(strcmp("00111010",param)==0)
	{
		fprintf(fp2,"urh_i ,");
	}
	else if(strcmp("00111011",param)==0)
	{
		fprintf(fp2,"urp_i ,") ;
	}
	else if(strcmp("00111100",param)==0)
	{
		fprintf(fp2,"uucp ,");
	}
	else if(strcmp("00111101",param)==0)
	{
		fprintf(fp2,"uucp path ,");
	}
	else if(strcmp("00111110",param)==0)
	{
		fprintf(fp2,"vmnet ,");
	}
	else if(strcmp("00111111",param)==0)
	{
		fprintf(fp2,"whois ,");
	}
	else if(strcmp("01000000",param)==0)
	{
		fprintf(fp2,"X11 ,");
	}
	else if(strcmp("01000001",param)==0)
	{
		fprintf(fp2,"Z39_50 ,");
	}
	else
	fprintf(fp2,"00000000      ,");
}


const char *flagtodec(char *param)					//flags to binary str
{
	if(strcmp("00000001",param)==0)
	{
		fprintf(fp2,"OTH ,");
	}
	else if(strcmp("00000010",param)==0)
	{
		fprintf(fp2,"REJ ");
	}
	else if(strcmp("00000011",param)==0)
	{
		fprintf(fp2,"RSTO ,");
	}
	else if(strcmp("00000100",param)==0)
	{
		fprintf(fp2,"RSTOS0 ,");
	}
	else if(strcmp("00000101",param)==0)
	{
		fprintf(fp2,"RSTR ,");
	}
	else if(strcmp("00000110",param)==0)
	{
		fprintf(fp2,"S0 ,");
	}
	else if(strcmp("00000111",param)==0)
	{
		fprintf(fp2,"S1 ,");
	}
	else if(strcmp("00001000",param)==0)
	{
		fprintf(fp2,"S2 ,");
	}
	else if(strcmp("00001001",param)==0)
	{
		fprintf(fp2,"S3 ,");
	}
	else if(strcmp("00001010",param)==0)
	{
		fprintf(fp2,"SF ,");
	}
	else if(strcmp("00001011",param)==0)
	{
		fprintf(fp2,"SH ,");
	}
	else
		fprintf(fp2,"00000000         ");

}


		

 main()
{
	int i,j,s;
	char binstr[41][50];
	char line[12350];
	FILE *fp1;
	fp1=fopen("binary.data","r");
	fp2=fopen("output.data","w");
	while(fgets(line,sizeof(line),fp1))
	{
	//	printf("%s\n",strlen(line));
		#define limit 16
		strcpy(binstr[0],substring(1,1+limit-1,line));				//duration 16
		todec(atoi(binstr[0]));
		s=1+limit;
		#undef limit
		#define limit 2
		strcpy(binstr[1],substring(s,(s+limit-1),line));			//protocol 2
		protosel(binstr[1]);
		s=s+limit;
		#undef limit
		//printf("%d",s);
		#define limit 8
		strcpy(binstr[2],substring(s,s+limit-1,line));
		servicetodec(binstr[2]);		//service 8
		s=s+limit;
		#undef limit
		#define limit 8
		strcpy(binstr[3],substring(s,s+limit-1,line));
		flagtodec(binstr[3]);											//flag 9
		s=s+limit;
		#undef limit
		#define limit 32
		strcpy(binstr[4],substring(s,s+limit-1,line));
		todec(atoi(binstr[4]));			// source bytes 32
		s=s+limit;
		#undef limit
		//printf("%d",s);
		#define limit 32
		strcpy(binstr[5],substring(s,s+limit-1,line));
		todec(atoi(binstr[5]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[6],substring(s,s+limit-1,line));			//land 1
		todec(atoi(binstr[6]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[7],substring(s,s+limit-1,line));			//wrongfragment 1
		todec(atoi(binstr[7]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[8],substring(s,s+limit-1,line));					//urgent 1
		todec(atoi(binstr[8]));
		s=s+limit;
		#undef limit
		//printf("%d",s);
		#define limit 8
		strcpy(binstr[9],substring(s,s+limit-1,line));			//hot
		todec(atoi(binstr[9]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[10],substring(s,s+limit-1,line));			//numfailed
		todec(atoi(binstr[10]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[11],substring(s,s+limit-1,line));			//loged in
		todec(atoi(binstr[11]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[12],substring(s,s+limit-1,line));			//num compromised
		todec(atoi(binstr[12]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[13],substring(s,s+limit-1,line));			//root to bin
		todec(atoi(binstr[13]));
		s=s+limit;
		#undef limit
		#define limit 1
		strcpy(binstr[14],substring(s,s+limit-1,line));			//su
		todec(atoi(binstr[14]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[15],substring(s,s+limit-1,line));			//mum root		
		todec(atoi(binstr[15]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[16],substring(s,s+limit-1,line));			//numfile
		todec(atoi(binstr[16]));
		s+=limit;
		#undef limit
		#define limit 1		
		strcpy(binstr[17],substring(s,s+limit-1,line));			//numshell
		todec(atoi(binstr[17]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[18],substring(s,s+limit-1,line));			//num access
		todec(atoi(binstr[18]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[19],substring(s,s+limit-1,line));			//num outbound	
		todec(atoi(binstr[19]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[20],substring(s,s+limit-1,line));			//ishost
		todec(atoi(binstr[20]));
		s+=limit;
		#undef limit
		#define limit 1
		strcpy(binstr[21],substring(s,s+limit-1,line));			//isguest
		todec(atoi(binstr[21]));
		s+=limit;
		#undef limit
		//printf("%d",s);
		#define limit 32
		strcpy(binstr[22],substring(s,s+limit-1,line));			//count
		todec(atoi(binstr[22]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[23],substring(s,s+limit-1,line));			//srvcount
		todec(atoi(binstr[23]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[24],substring(s,s+limit-1,line));			//serror
		todec(atoi(binstr[24]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[25],substring(s,s+limit-1,line));			//srverror
		todec(atoi(binstr[25]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[26],substring(s,s+limit-1,line));			//rerror
		todec(atoi(binstr[26]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[27],substring(s,s+limit-1,line));			//server error
		todec(atoi(binstr[27]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[28],substring(s,s+limit-1,line));			//same serever
		todec(atoi(binstr[28]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[29],substring(s,s+limit-1,line));			//dielse iff servr
		todec(atoi(binstr[29]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[30],substring(s,s+limit-1,line));			//serv delse iff
		todec(atoi(binstr[30]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[31],substring(s,s+limit-1,line));			//desthostfp2
		todec(atoi(binstr[31]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[32],substring(s,s+limit-1,line));			//desthostserver
		todec(atoi(binstr[32]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[33],substring(s,s+limit-1,line));			//dest host sam srvr
		todec(atoi(binstr[33]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[34],substring(s,s+limit-1,line));			//dest host delse iff serv
		todec(atoi(binstr[34]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[35],substring(s,s+limit-1,line));			//dest host sam sorce port
		todec(atoi(binstr[35]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[36],substring(s,s+limit-1,line));			//dest host delse iff sorce port
		todec(atoi(binstr[36]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[37],substring(s,s+limit-1,line));			//dhsrc
		todec(atoi(binstr[37]));
		s+=limit;
		#undef limit
		#define limit 32
		//printf("%d",s);
		strcpy(binstr[38],substring(s,s+limit-1,line));			//dhs.....
		todec(atoi(binstr[38]));
		s+=limit;
		#undef limit
		#define limit 32
		strcpy(binstr[39],substring(s,s+limit-1,line));			//dhs..ssrt
		todec(atoi(binstr[39]));
		s+=limit;
		#undef limit
		#define limit 32
		//printf("%d",s);
		strcpy(binstr[40],substring(s,s+limit-1,line));			//dhssrvr
		todec(atoi(binstr[40]));
		s+=limit;
		#undef limit
			
	
	fprintf(fp2,"\n");	
	}
	
	//printf("%s",binstr[0]);
	//j=strlen(line);
	//printf("%d",strlen(line));
}
	
