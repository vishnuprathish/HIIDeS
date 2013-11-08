#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int compare_rules(char src_ip[13],char dest_ip[13],char src_pno[6],char dest_pno[6],char duration[9],char protocol[2],char num_pso[11],char num_psr[11])
{
	FILE *fp ,*fp1, *fp2;
	char line[100],dip[100][13]={0},sip[100][13]={0},spn[100][6]={0},dpn[100][6]={0},dur[100][9]={0},prot[100][2]={0},npso[100][11]={0},npsr[100][11]={0};
	fp=fopen("ruless.dat","r");
	
	fp1=fopen("log.dat","a+");
	fp2=fopen("buffer.dat","r");
	int flag=0,i,lcount=0,j;
	time_t now;
	time(&now);
	while( fgets(line, sizeof(line), fp) != NULL )
	{
		
		//printf("%d",strlen(line));
			
         j=0;
		for(i=0;i<12;i++)
		{
			sip[lcount][j]=line[i];
			j++;
			
		}
		j=0;
		for(i=12;i<24;i++)
		{
				
			dip[lcount][j]=line[i];
			j++;
		}	
		j=0;
		for(i=24;i<29;i++)
		{
			spn[lcount][j]=line[i];
			j++;
		
		}	
		j=0;
		for(i=29;i<34;i++)
		{
				
			dpn[lcount][j]=line[i];
			j++;
		}	

		j=0;
		for(i=34;i<42;i++)
		{
				
			dur[lcount][j]=line[i];
			j++;
		}	
		j=0;
		for(i=44;i<45;i++)
		{
				
			prot[lcount][j]=line[i];
			j++;
		}	
		j=0;
		for(i=45;i<55;i++)
		{
				
			npso[lcount][j]=line[i];
			j++;
		}	
		j=0;
		for(i=55;i<65;i++)
		{
				
			npsr[lcount][j]=line[i];
			j++;
		}		
		
		
		lcount++;
	
	}
	
	//comparing
	for(i=0;i<lcount;i++)
	{
	
	    //printf("\n%s___%s___%s___%s___%s___%s___%s___%s___\n",sip[i],dip[i],spn[i],dpn[i],dur[i],prot[i],npso[i],npsr[i]);
		
	    if((strcmp(src_ip,sip[i])==0)|| (strcmp(dest_ip,dip[i])==0)||(strcmp(src_pno,spn[i])==0) || (strcmp(dest_pno,dpn[i])==0))
	    {	
		 printf("Source IP match");
	     flag=1;	
	     fprintf(fp1,"%s \t%s\n",ctime(&now),src_ip);
     	}	
		//printf("--%s=",src_ip);
		//printf("%s--",sip[i]);
		
		//,char dest_ip[13],char src_pno[6],char dest_pno[6],char duration[6],char protocol[2],char num_pso[11],char num_psr[11])
	
	
    }
	 if(flag==0)
	 printf("no rules violated");
	
	fclose(fp);
	fclose(fp1);
	return 0;
}
