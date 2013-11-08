#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

			//global variable prescribed to this function only. change this to static
	char result[50]; 
	
	 void tobinStr(int i)
 {                        //to convert an integer to binary string.
         int j=0;char t[2];  
          if(i!=0)
  {
     j=i;
   tobinStr(i>>1);
    sprintf(t,"%d",j&0x01);
            strcat(result,t);
         }
 }        
char * tobinary(int value)        //temporay adjustment. change.
{
        
 //printf("%d\n",value);

 strcpy(result,"");
 

        if(value==0)
            return "0";
        tobinStr(value);
 //strcat(result,"\0");        
 //strcpy(temp,result);
 
        
        return result;
}
		
char *durtobin(char *param)				//16 bits
{
	#define limit 16	
	char temp[limit];
	int i;
	//cout<<"--"<<param<<"--";
	static char t[limit];
	strcpy(temp,tobinary(atoi(param)));
	//printf("#%s#",temp);
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	//printf("%s",t);
	strcat(t,temp);
	//cout<<"--"<<t<<"--";
	return t;
	#undef limit
}

		
const char *protobin(char *param)
{
	if(strcmp("tcp",param)==0)
	{
		return "01";
	}
	if(strcmp("udp",param)==0)
	{
		return "10";
	}
	if(strcmp("icmp",param)==0)
	{
		return "11";
	}
	return "00";
}

const char *servicetobin(char *param)					//service
{
	if(strcmp("auth",param)==0)
	{
		return "00000001";
	}
	if(strcmp("bgp",param)==0)
	{
		return "00000010";
	}
	if(strcmp("courier",param)==0)
	{
		return "00000011";
	}
	if(strcmp("csnet_ns",param)==0)
	{
		return "00000100";
	}
	if(strcmp("ctf",param)==0)
	{
		return "00000101";
	}
	if(strcmp("daytime",param)==0)
	{
		return "00000110";
	}
	if(strcmp("discard",param)==0)
	{
		return "00000111";
	}
	if(strcmp("domain",param)==0)
	{
		return "00001000";
	}
	if(strcmp("domain_u",param)==0)
	{
		return "00001001";
	}
	if(strcmp("echo",param)==0)
	{
		return "00001010";
	}
	if(strcmp("eco_i",param)==0)
	{
		return "00001011";
	}
	if(strcmp("ecr_i",param)==0)
	{
		return "00001100";
	}
	if(strcmp("efs",param)==0)
	{
		return "00001101";
	}
	if(strcmp("exec",param)==0)
	{
		return "00001110";
	}
	
	if(strcmp("finger",param)==0)
	{
		return "00001111";
	}
	if(strcmp("ftp",param)==0)
	{
		return "00010000";
	}
	if(strcmp("ftp_data",param)==0)
	{
		return "00010001";
	}
	if(strcmp("gopher",param)==0)
	{
		return "00010010";
	}
	if(strcmp("hostnames",param)==0)
	{
		return "00010011";
	}
	if(strcmp("http",param)==0)
	{
		return "00010100";
	}
	if(strcmp("http_443",param)==0)
	{
		return "00010101";
	}
	if(strcmp("imap4",param)==0)
	{
		return "00010110";
	}
	if(strcmp("IRC",param)==0)
	{
		return "00010111";
	}
	if(strcmp("iso_tsap",param)==0)
	{
		return "00011000";
	}
	if(strcmp("klogin",param)==0)
	{
		return "00011001";
	}
	if(strcmp("kshell",param)==0)
	{
		return "00011010";
	}
	if(strcmp("ldap",param)==0)
	{
		return "00011011";
	}
	if(strcmp("link",param)==0)
	{
		return "00011100";
	}
	if(strcmp("login",param)==0)
	{
		return "00011101";
	}
	if(strcmp("mtp",param)==0)
	{
		return "00011110";
	}
	if(strcmp("name",param)==0)
	{
		return "00011111";
	}
	if(strcmp("netbios_dgm",param)==0)
	{
		return "00100000";
	}
	if(strcmp("netbios_ns",param)==0)
	{
		return "00100001";
	}
	if(strcmp("netbios_ssn",param)==0)
	{
		return "00100010";
	}
	if(strcmp("netstat",param)==0)
	{
		return "00100011";
	}
	if(strcmp("nnsp",param)==0)
	{
		return "00100100";
	}
	if(strcmp("nntp",param)==0)
	{
		return "00100101";
	}
	if(strcmp("ntp_u",param)==0)
	{
		return "00100110";
	}
	if(strcmp("other",param)==0)
	{
		return "00100111";
	}
	if(strcmp("pm_dump",param)==0)
	{
		return "00101000";
	}
	if(strcmp("pop_2",param)==0)
	{
		return "00101001";
	}
	if(strcmp("pop_3",param)==0)
	{
		return "00101010";
	}
	if(strcmp("printer",param)==0)
	{
		return "00101011";
	}
	if(strcmp("private",param)==0)
	{
		return "00101100";
	}
	if(strcmp("red_i",param)==0)
	{
		return "00101101";
	}
	if(strcmp("remote_job",param)==0)
	{
		return "00101110";
	}
	if(strcmp("rje",param)==0)
	{
		return "00101111";
	}
	if(strcmp("shell",param)==0)
	{
		return "00110000";
	}
	if(strcmp("smtp",param)==0)
	{
		return "00110001";
	}
	if(strcmp("sql_net",param)==0)
	{
		return "00110010";
	}
	if(strcmp("ssh",param)==0)
	{
		return "00110011";
	}
	if(strcmp("sunrpc",param)==0)
	{
		return "00110100";
	}
	if(strcmp("supdup",param)==0)
	{
		return "00110100";
	}
	if(strcmp("systat",param)==0)
	{
		return "00110101";
	}
	if(strcmp("telnet",param)==0)
	{
		return "00110110";
	}
	if(strcmp("tftp_u",param)==0)
	{
		return "00110111";
	}
	if(strcmp("tim_i",param)==0)
	{
		return "00111000";
	}
	if(strcmp("time",param)==0)
	{
		return "00111001";
	}
	if(strcmp("urh_i",param)==0)
	{
		return "00111010";
	}
	if(strcmp("urp_i",param)==0)
	{
		return "00111011";
	}
	if(strcmp("uucp",param)==0)
	{
		return "00111100";
	}
	if(strcmp("uucp_path",param)==0)
	{
		return "00111101";
	}
	if(strcmp("vmnet",param)==0)
	{
		return "00111110";
	}
	if(strcmp("whois",param)==0)
	{
		return "00111111";
	}
	if(strcmp("X11",param)==0)
	{
		return "01000000";
	}
	if(strcmp("Z39_50",param)==0)
	{
		return "01000001";
	}
	return "00000000";
}

const char *flagtobin(char *param)					//flags to binary str
{
	if(strcmp("OTH",param)==0)
	{
		return "00000001";
	}
	if(strcmp("REJ",param)==0)
	{
		return "00000010";
	}
	if(strcmp("RSTO",param)==0)
	{
		return "00000011";
	}
	if(strcmp("RSTOS0",param)==0)
	{
		return "00000100";
	}
	if(strcmp("RSTR",param)==0)
	{
		return "00000101";
	}
	if(strcmp("S0",param)==0)
	{
		return "00000110";
	}
	if(strcmp("S1",param)==0)
	{
		return "00000111";
	}
	if(strcmp("S2",param)==0)
	{
		return "00001000";
	}
	if(strcmp("S3",param)==0)
	{
		return "00001001";
	}
	if(strcmp("SF",param)==0)
	{
		return "00001010";
	}
	if(strcmp("SH",param)==0)
	{
		return "00001011";
	}
		return "00000000";

}

const char *srcbytestobin(char *param)				//source byts
{
	//if 
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	
	int x=atoi(param);
	strcpy(temp,tobinary(x));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	
	return t;
	#undef limit  
	
}

char *destbytestobin(char *param)					//dest bytes
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit 
	
	
}

char *landtobin(char *param)					//LAND
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
	
}

char *wrongfragtobin(char *param)				//wrong fragment
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *urgenttobin(char *param)					//urgent
{
	#define limit 1
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *hottobin(char *param)						//hot 
{
	#define limit 8
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numfailedtobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *loggedtobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numcompromisedtobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *roottobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *sutobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numroottobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numfiletobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numshellstobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numaccesstobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *numoutboundtobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}


char *ishosttobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}


char *isguesttobin(char *param)
{
	#define limit 1	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *counttobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *srvcounttobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}
char *serrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}
char *srverrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *rerrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *servrerrortobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *sameservtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *diffservtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *srvdiffhosttobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *desthosttobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *desthostservtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *desthostsameservtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *desthostdiffservtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *desthostsamesrcport(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *dhsdsrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *dhsrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *dhssrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *dhsrrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}

char *dhsrvrtobin(char *param)
{
	#define limit 32	
	char temp[limit];
	int i;
	static char t[limit];
	strcpy(t,"");
	strcpy(temp,tobinary(atoi(param)));
	for(i=0;i<(limit-strlen(temp));i++)
	{
		t[i]='0';
	}
	t[i]='\0';
	strcat(t,temp);
	return t;
	#undef limit
}




int main(int argc, char** argv)
{
	int testcount=0;
	  char line[200];
      FILE *fp = fopen("training1.data","r");
      char str[50][10];
      char bitstr[41][50];
      char strline[12350];
     while(fgets(line,sizeof(line),fp))
		{
  //fgets(line,sizeof(line),fp);
      
	//	printf("%s\n",line);
	    strcpy(str[0],strtok(line,","));
		for(int i=1;i<42;i++)
		{
			strcpy(str[i],strtok(NULL,","));
		}
														//HERE str[i] contains each attribute
		
	//	for(int i=0;i<42;i++)
	//		cout<<str[i]<<" ";
		
		strcpy(bitstr[0],durtobin(str[0]));			//Duration
		strcpy(bitstr[1],protobin(str[1]));			//protocol
		strcpy(bitstr[2],servicetobin(str[2]));		//Service
		strcpy(bitstr[3],flagtobin(str[3]));		//Flags
		strcpy(bitstr[4],srcbytestobin(str[4]));	//srcbytes
		strcpy(bitstr[5],destbytestobin(str[5]));			//destbytes
		strcpy(bitstr[6],landtobin(str[6]));		//land	
		strcpy(bitstr[7],wrongfragtobin(str[7]));			//wf
		strcpy(bitstr[8],urgenttobin(str[8]));			//urgent
		strcpy(bitstr[9],hottobin(str[9]));			//hot
		strcpy(bitstr[10],numfailedtobin(str[10]));		//nf logins
		strcpy(bitstr[11],loggedtobin(str[11])); 		//logged in
		strcpy(bitstr[12],numcompromisedtobin(str[12]));		//nc
		strcpy(bitstr[13],roottobin(str[13]));		//root shell
		strcpy(bitstr[14],sutobin(str[14]));		//su attempted
		strcpy(bitstr[15],numroottobin(str[15]));		//num root
		strcpy(bitstr[16],numfiletobin(str[16]));			//num file creations
		strcpy(bitstr[17],numshellstobin(str[17]));		//num shells
		strcpy(bitstr[18],numaccesstobin(str[18]));		//num acess files
		strcpy(bitstr[19],numoutboundtobin(str[19]));		//num outbound cmds
		strcpy(bitstr[20],ishosttobin(str[20]));		//is host login
		strcpy(bitstr[21],isguesttobin(str[21]));		//is guest login
		strcpy(bitstr[22],counttobin(str[22]));		//count
		strcpy(bitstr[23],srvcounttobin(str[23]));		//serv count
		strcpy(bitstr[24],serrtobin(str[24]));		//serror_rate
		strcpy(bitstr[25],srverrtobin(str[25]));		//srv_serror_rate
		strcpy(bitstr[26],rerrtobin(str[26]));		//rerror_rate
		strcpy(bitstr[27],srverrtobin(str[27]));		//srv_rerror_rate
		strcpy(bitstr[28],sameservtobin(str[28]));		//same_srv_rate
		strcpy(bitstr[29],diffservtobin(str[29]));		//diff_srv_rate
		strcpy(bitstr[30],srvdiffhosttobin(str[30]));		//srv_diff_host_rate
		strcpy(bitstr[31],desthosttobin(str[31]));		//dst_host_count
		strcpy(bitstr[32],desthostservtobin(str[32]));		//dst_host_srv_count
		strcpy(bitstr[33],desthostsameservtobin(str[33]));		//dst_host_same_srv_rate
		strcpy(bitstr[34],desthostdiffservtobin(str[34]));		//dst_host_diff_srv_rate
		strcpy(bitstr[35],desthostsamesrcport(str[35]));		//dst_host_same_src_port_rate
		strcpy(bitstr[36],dhsdsrtobin(str[36]));		//dst_host_srv_diff_host_rate
		strcpy(bitstr[37],dhsrtobin(str[37]));		//dst_host_serror_rate
		strcpy(bitstr[38],dhssrtobin(str[38]));		//dst_host_srv_serror_rate
		strcpy(bitstr[39],dhsrrtobin(str[39]));		//dst_host_rerror_rate
		strcpy(bitstr[40],dhsrvrtobin(str[40]));		//dst_host_srv_rerror_rate
			
				
			strcpy(strline,"");
					
			
		for(int j=0;j<41;j++)
			{
				strcat(strline,bitstr[j]);
				//strcat(strline," ");
			}
				strcat(strline,"\n");
			
			testcount++;
			//cout<<":"<<testcount<<"-"<<strline;
			
			//if(strlen(strline)<=300)
			cout<<strline;
			strcpy(strline,"");
	//		sleep(1);
			/*FILE *fp;
			fp=fopen("binary.data","a+");
				fputs(strline,fp);
				fclose(fp); */
	
      }
      fclose(fp);
	return 0;
}
