#include<stdio.h>
#include<string.h>
#define threshold 55
main()

{
	FILE *fp, *fp1 ,*fp2 ;
	char ch;
	int i,j,k;
	float score=0;
	char pack_par[50][50],rule_par[50][50];
	char line[200],line1[200];
	printf("helo");
	fp2=fopen("log1.dat","a+");
	fp=fopen("out_r.data","r");
	//fp1=fopen("training1.data","r");
     while(fgets(line,sizeof(line),fp))
	{
      printf("$$$$$");
	    strcpy(rule_par[0],strtok(line,","));
		for(i=1;i<42;i++)
		{
			strcpy(rule_par[i],strtok(NULL,","));
		}	
	  //	printf("%s   +",pack_par[i]);
     	  
     
 		  fp1=fopen("output.data","r");
          while(fgets(line1,sizeof(line1),fp1))
	      {
  
	      strcpy(pack_par[0],strtok(line1,","));
		   for(j=1;j<42;j++)
		   {
			 strcpy(pack_par[j],strtok(NULL,","));
			}
			
			
	       for(j=1;j<41;j++)								//comparison..
		    {
            // printf("****");
			 if(strcmp(rule_par[j],pack_par[j])==0)
			 {
				 score++;
				 //printf("***%f*",score);
			 }
			}
		 	 score=score/40*100;
			 fprintf(fp2,"%f \n",score);
	         if(score>threshold)
	          {
		        if(!strcmp(rule_par[41],"normal.\n"))
				{
		           printf("\nfail--%f--%s",score,rule_par[41]);
			     }
	           else
                printf("\nsuccess-intrusion detected!---%s",rule_par[41]);
		      } 
			  else{
				  printf("\nno match %f",score); 
			   }
			  
	         score=0;
	  
	     printf("&&&&&");
	
      	
      	  
        }
	   fclose(fp1);
	   printf("^^^^^");
     }
  	fcloseall();
    
      

 }

