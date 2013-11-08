

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

char result[20];			//global variable prescribed to this function only. change this to static
void tobinStr(int i)
{						//to convert an integer to binary string.
  int j=0;char t[2];  
  if(i!=0){
  j=i;
  tobinStr(i>>1);
  sprintf(t,"%d",j&0x01);
  
  strcat(result,t);
   }
	
}
		string tobinary(int value)		//temporay adjustment. change.
		{
			//char zero[2]="0";
			string temp;
			if(value==0)
				return "0";
			tobinStr(value);
			temp.assign(result);
			strcpy(result,"");
			return temp;
		}
		
string durtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

		
const string protobin(string param)
{
	if(param.compare("tcp")==0)
	{
		return "01";
	}
	if(param.compare("udp")==0)
	{
		return "10";
	}
	if(param.compare("icmp")==0)
	{
		return "11";
	}
	return "00";
}

const string servicetobin(string param)					//service
{
	if(param.compare("auth")==0)
	{
		return "00000001";
	}
	if(param.compare("bgp")==0)
	{
		return "00000010";
	}
	if(param.compare("courier")==0)
	{
		return "00000011";
	}
	if(param.compare("csnet_ns")==0)
	{
		return "00000100";
	}
	if(param.compare("ctf")==0)
	{
		return "00000101";
	}
	if(param.compare("daytime")==0)
	{
		return "00000110";
	}
	if(param.compare("discard")==0)
	{
		return "00000111";
	}
	if(param.compare("domain")==0)
	{
		return "00001000";
	}
	if(param.compare("domain_u")==0)
	{
		return "00001001";
	}
	if(param.compare("echo")==0)
	{
		return "00001010";
	}
	if(param.compare("eco_i")==0)
	{
		return "00001011";
	}
	if(param.compare("ecr_i")==0)
	{
		return "00001100";
	}
	if(param.compare("efs")==0)
	{
		return "00001101";
	}
	if(param.compare("exec")==0)
	{
		return "00001110";
	}
	
	if(param.compare("finger")==0)
	{
		return "00001111";
	}
	if(param.compare("ftp")==0)
	{
		return "00010000";
	}
	if(param.compare("ftp_data")==0)
	{
		return "00010001";
	}
	if(param.compare("gopher")==0)
	{
		return "00010010";
	}
	if(param.compare("hostnames")==0)
	{
		return "00010011";
	}
	if(param.compare("http")==0)
	{
		return "00010100";
	}
	if(param.compare("http_443")==0)
	{
		return "00010101";
	}
	if(param.compare("imap4")==0)
	{
		return "00010110";
	}
	if(param.compare("IRC")==0)
	{
		return "00010111";
	}
	if(param.compare("iso_tsap")==0)
	{
		return "00011000";
	}
	if(param.compare("klogin")==0)
	{
		return "00011001";
	}
	if(param.compare("kshell")==0)
	{
		return "00011010";
	}
	if(param.compare("ldap")==0)
	{
		return "00011011";
	}
	if(param.compare("link")==0)
	{
		return "00011100";
	}
	if(param.compare("login")==0)
	{
		return "00011101";
	}
	if(param.compare("mtp")==0)
	{
		return "00011110";
	}
	if(param.compare("name")==0)
	{
		return "00011111";
	}
	if(param.compare("netbios_dgm")==0)
	{
		return "00100000";
	}
	if(param.compare("netbios_ns")==0)
	{
		return "00100001";
	}
	if(param.compare("netbios_ssn")==0)
	{
		return "00100010";
	}
	if(param.compare("netstat")==0)
	{
		return "00100011";
	}
	if(param.compare("nnsp")==0)
	{
		return "00100100";
	}
	if(param.compare("nntp")==0)
	{
		return "00100101";
	}
	if(param.compare("ntp_u")==0)
	{
		return "00100110";
	}
	if(param.compare("other")==0)
	{
		return "00100111";
	}
	if(param.compare("pm_dump")==0)
	{
		return "00101000";
	}
	if(param.compare("pop_2")==0)
	{
		return "00101001";
	}
	if(param.compare("pop_3")==0)
	{
		return "00101010";
	}
	if(param.compare("printer")==0)
	{
		return "00101011";
	}
	if(param.compare("private")==0)
	{
		return "00101100";
	}
	if(param.compare("red_i")==0)
	{
		return "00101101";
	}
	if(param.compare("remote_job")==0)
	{
		return "00101110";
	}
	if(param.compare("rje")==0)
	{
		return "00101111";
	}
	if(param.compare("shell")==0)
	{
		return "00110000";
	}
	if(param.compare("smtp")==0)
	{
		return "00110001";
	}
	if(param.compare("sql_net")==0)
	{
		return "00110010";
	}
	if(param.compare("ssh")==0)
	{
		return "00110011";
	}
	if(param.compare("sunrpc")==0)
	{
		return "00110100";
	}
	if(param.compare("supdup")==0)
	{
		return "00110100";
	}
	if(param.compare("systat")==0)
	{
		return "00110101";
	}
	if(param.compare("telnet")==0)
	{
		return "00110110";
	}
	if(param.compare("tftp_u")==0)
	{
		return "00110111";
	}
	if(param.compare("tim_i")==0)
	{
		return "00111000";
	}
	if(param.compare("time")==0)
	{
		return "00111001";
	}
	if(param.compare("urh_i")==0)
	{
		return "00111010";
	}
	if(param.compare("urp_i")==0)
	{
		return "00111011";
	}
	if(param.compare("uucp")==0)
	{
		return "00111100";
	}
	if(param.compare("uucp_path")==0)
	{
		return "00111101";
	}
	if(param.compare("vmnet")==0)
	{
		return "00111110";
	}
	if(param.compare("whois")==0)
	{
		return "00111111";
	}
	if(param.compare("X11")==0)
	{
		return "01000000";
	}
	if(param.compare("Z39_50")==0)
	{
		return "01000001";
	}
	return "00000000";
}

const string flagtobin(string param)					//flags to binary str
{
	if(param.compare("OTH")==0)
	{
		return "00000001";
	}
	if(param.compare("REJ")==0)
	{
		return "00000010";
	}
	if(param.compare("RSTO")==0)
	{
		return "00000011";
	}
	if(param.compare("RSTOS0")==0)
	{
		return "00000100";
	}
	if(param.compare("RSTR")==0)
	{
		return "00000101";
	}
	if(param.compare("S0")==0)
	{
		return "00000110";
	}
	if(param.compare("S1")==0)
	{
		return "00000111";
	}
	if(param.compare("S2")==0)
	{
		return "00001000";
	}
	if(param.compare("S3")==0)
	{
		return "00001001";
	}
	if(param.compare("SF")==0)
	{
		return "00001010";
	}
	if(param.compare("SH")==0)
	{
		return "00001011";
	}
		return "00000000";

}

const string srcbytestobin(string param)				//source byts
{
	return tobinary(atoi(param.c_str()));
}

string destbytestobin(string param)					//dest bytes
{
		return tobinary(atoi(param.c_str()));

}

string landtobin(string param)					//LAND
{
	return tobinary(atoi(param.c_str()));
	
}

string wrongfragtobin(string param)				//wrong fragment
{
	return tobinary(atoi(param.c_str()));
}

string urgenttobin(string param)					//urgent
{
	return tobinary(atoi(param.c_str()));
}

string hottobin(string param)						
{
	return tobinary(atoi(param.c_str()));
}

string numfailedtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string loggedtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numcompromisedtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string roottobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string sutobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numroottobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numfiletobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numshellstobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numaccesstobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string numoutboundtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}


string ishosttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}


string isguesttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string counttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string srvcounttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}
string serrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}
string srverrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string rerrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string servrerrortobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string sameservtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string diffservtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string srvdiffhosttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string desthosttobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string desthostservtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string desthostsameservtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string desthostdiffservtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string desthostsamesrcport(string param)
{
	return tobinary(atoi(param.c_str()));
}

string dhsdsrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string dhsrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string dhssrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string dhsrrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}

string dhsrvrtobin(string param)
{
	return tobinary(atoi(param.c_str()));
}




int main(int argc, char** argv)
{
	  char line[200];
      FILE *fp = fopen("training.data","r");
      string str[50];
      string bitstr[41];
      string strline;
     while(fgets(line,sizeof(line),fp))
		{
   //fgets(line,sizeof(line),fp);
      
	//	printf("%s\n",line);
	    str[0].assign(strtok(line,","));
		for(int i=1;i<42;i++)
		{
			str[i].assign(strtok(NULL,","));
		}
		//HERE str[i] contains each attribute
		
		bitstr[0].assign(durtobin(str[0]));			//Duration
		bitstr[1].assign(protobin(str[1]));			//protocol
		bitstr[2].assign(servicetobin(str[2]));		//Service
		bitstr[3].assign(flagtobin(str[3]));		//Flags
		bitstr[4].assign(srcbytestobin(str[4]));	//srcbytes
		bitstr[5].assign(destbytestobin(str[5]));			//destbytes
		bitstr[6].assign(landtobin(str[6]));		//land	
		bitstr[7].assign(wrongfragtobin(str[7]));			//wf
		bitstr[8].assign(urgenttobin(str[8]));			//urgent
		bitstr[9].assign(hottobin(str[9]));			//hot
		bitstr[10].assign(numfailedtobin(str[10]));		//nf logins
		bitstr[11].assign(loggedtobin(str[11])); 		//logged in
		bitstr[12].assign(numcompromisedtobin(str[12]));		//nc
		bitstr[13].assign(roottobin(str[13]));		//root shell
		bitstr[14].assign(sutobin(str[14]));		//su attempted
		bitstr[15].assign(numroottobin(str[15]));		//num root
		bitstr[16].assign(numfiletobin(str[16]));			//num file creations
		bitstr[17].assign(numshellstobin(str[17]));		//num shells
		bitstr[18].assign(numaccesstobin(str[18]));		//num acess files
		bitstr[19].assign(numoutboundtobin(str[19]));		//num outbound cmds
		bitstr[20].assign(ishosttobin(str[20]));		//is host login
		bitstr[21].assign(isguesttobin(str[21]));		//is guest login
		bitstr[22].assign(counttobin(str[22]));		//count
		bitstr[23].assign(srvcounttobin(str[23]));		//serv count
		bitstr[24].assign(serrtobin(str[24]));		//serror_rate
		bitstr[25].assign(srverrtobin(str[25]));		//srv_serror_ra te
		bitstr[26].assign(rerrtobin(str[26]));		//rerror_rate
		bitstr[27].assign(srverrtobin(str[27]));		//srv_rerror_rate
		bitstr[28].assign(sameservtobin(str[28]));		//same_srv_rate
		bitstr[29].assign(diffservtobin(str[29]));		//diff_srv_rate
		bitstr[30].assign(srvdiffhosttobin(str[30]));		//srv_diff_host_rate
		bitstr[31].assign(desthosttobin(str[31]));		//dst_host_count
		bitstr[32].assign(desthostservtobin(str[32]));		//dst_host_srv_count
		bitstr[33].assign(desthostsameservtobin(str[33]));		//dst_host_same_srv_rate
		bitstr[34].assign(desthostdiffservtobin(str[34]));		//dst_host_diff_srv_rate
		bitstr[35].assign(desthostsamesrcport(str[35]));		//dst_host_same_src_port_rate
		bitstr[36].assign(dhsdsrtobin(str[36]));		//dst_host_srv_diff_host_rate
		bitstr[37].assign(dhsrtobin(str[37]));		//dst_host_serror_rate
		bitstr[38].assign(dhssrtobin(str[38]));		//dst_host_srv_serror_rate
		bitstr[39].assign(dhsrrtobin(str[39]));		//dst_host_rerror_rate
		bitstr[40].assign(dhsrvrtobin(str[40]));		//dst_host_srv_rerror_rate
			
//		cout<<"==="<<bitstr[40]<<"====";
		
		strline.clear();
		for(int j=0;j<40;j++)
			{
				strline.append(bitstr[j]);
			}
			
		///for(int j=0;j<40;j++)
			cout<<"\n-"<<strline;
		for(int j=0;j<40;j++)
			bitstr[j].clear();
		//	sleep(1);
      }
   
      fclose(fp);
	return 0;
}
