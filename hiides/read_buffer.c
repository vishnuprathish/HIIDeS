#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "compare_rules.c"
int llcount;
char line[100];
int i,j;
char src_ip[1][13]={0},dest_ip[1][13]={0},src_pno[1][6]={0},dest_pno[1][6]={0}, duration[1][9]={0},protocol[1][2]={0}, num_pso[1][11]={0},num_psr[1][11]={0};
read_buffer()
{
	FILE *fp2;
	
	fp2=fopen("buffer.dat","r");
	//while( fgets(line, sizeof(line), fp2) != NULL )
	while(1)
	while(fscanf(fp2, "%s ", line) != EOF)
	{
		
		printf("\nline length si     %s ***** %d\n",line,llcount);
		
	
		
			
         j=0;
		for(i=0;i<12;i++)
		{
			src_ip[llcount][j]=line[i];
			j++;
			
		}
		src_ip[llcount][j]='\0';
		printf("src ip  %s\n",src_ip[llcount]);
		j=0;
		for(i=12;i<24;i++)
		{
				
			dest_ip[llcount][j]=line[i];
			j++;
		}
		dest_ip[llcount][j]='\0';
		printf("dest ip     %s\n",dest_ip[llcount]);	
		j=0;
		for(i=24;i<29;i++)
		{
			src_pno[llcount][j]=line[i];
	 		j++;
		
		}	
		src_pno[llcount][j]='\0';
		printf("src    pno   %s\n",src_pno[llcount]);
		j=0;
		for(i=29;i<34;i++)
		{
				
			dest_pno[llcount][j]=line[i];
			j++;
		}	
		dest_pno[llcount][j]='\0';
		printf("dst pno %s\n",dest_pno[llcount]);

		j=0;
		for(i=34;i<42;i++)
		{
				
			duration[llcount][j]=line[i];
			j++;
		}	
		duration[llcount][j]='\0';
		printf("duartion %s\n",duration[llcount]);
		j=0;
		for(i=42;i<43;i++)
		{
				
			protocol[llcount][j]=line[i];
			j++;
		}	
		protocol[llcount][j]='\0';
		printf("protocol             %s\n",protocol[llcount]);
		j=0;
		for(i=43;i<53;i++)
		{
				
			num_pso[llcount][j]=line[i];
			j++;
		}
		num_pso[llcount][j]='\0';	
		printf("number bytes orginator%s\n",num_pso[llcount]);
		j=0;
		for(i=53;i<63;i++)
		{
				
			num_psr[llcount][j]=line[i];
			j++;
		}	
		num_psr[llcount][j]='\0';	
		
		printf("no of bystes resoponder%s\n",num_psr[llcount]);
		
		compare_rules(src_ip[llcount],dest_ip[llcount],src_pno[llcount],dest_pno[llcount],duration[llcount],protocol[llcount],num_pso[llcount],num_psr[llcount]);
	//	llcount++;
	
	}
	fclose(fp2);
	
	
}
	
