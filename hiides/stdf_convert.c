#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
char b[100],chr[100],temp1[100],chr1[100],chr2[100],temp2[100];
/* TO Convert no of bytes up/down to standard format */
char* stdfnfb(int p)
{
	int l,i,j;
   
   sprintf(chr1,"%d",p);
   l=strlen(chr1);
   for(i=0;i<l;i++)
   {
	   temp1[10-i-1]=chr1[l-i-1];
   }
   for(i=0;i<10-l;i++)
   {
	   temp1[i]='0';
   }
   temp1[10]='\0';
   //printf("\n the no bytes is     %s" ,temp1);
   return temp1;
}
   
/* TO Convert duration to standard foramt */
char* stdfdur(int p)
{
	int l,i,j;
   
   sprintf(chr2,"%d",p);
   l=strlen(chr2);
   for(i=0;i<l;i++)
   {
	   temp2[8-i-1]=chr2[l-i-1];
   }
   for(i=0;i<8-l;i++)
   {
	   temp2[i]='0';
   }
   temp2[8]='\0';
   //printf("\n the duration is     %s" ,temp2);
   return temp2;
}


/* TO Convert ip to standard foramt */
char * stdfip(char a[])
{
	char *ch;
	strcpy(b,"");
	ch=strtok(a,".");
    int i=0,j=0;
  while(ch!=NULL)
  {
	  if(strlen(ch)==1)
      {  
		b[i++]='0';
		b[i++]='0';
      }
	if(strlen(ch)==2)
	b[i++]='0';
    for(j=0;j<strlen(ch);j++)
	{
	   b[i++]=ch[j];
      	
	}
	
	ch = strtok (NULL, ".");
  }
  
  //printf("%s",b);
	return(b);
}

/* TO Convert port to standard foramt */
char * stdfp(int p)
 {
   int l;
   char temp[100];
   sprintf(chr,"%d",p);
   l=strlen(chr);
   strcpy(temp,chr);
   if(l==0)
   {
	   chr[0]='0';
	   chr[1]='0';
	   chr[2]='0';
	   chr[3]='0';
	   chr[4]='0';
	  
   }
   else if(l==1)
   {

	   chr[0]='0';
	   chr[1]='0';
	   chr[2]='0';
	   chr[3]='0';
	   chr[4]=temp[0];
	}
	else if(l==2)
	{
		chr[0]='0';
	    chr[1]='0';
		chr[2]='0';
		chr[3]=temp[0];
		chr[4]=temp[1];
	   
     }
	 else if(l==3)
	 {
		 chr[0]='0';
		 chr[1]='0';
		 chr[2]=temp[0];
		 chr[3]=temp[1];
		 chr[4]=temp[2];
	 }
	 else if(l==4)
	 {
		 chr[0]='0';
		 chr[1]=temp[0];
		 chr[2]=temp[1];
		 chr[3]=temp[2];
		 chr[4]=temp[3];
	 }
   	 chr[5]='\0';
	 //printf("IN function check port is %s \n",chr);
	 return chr;
 }
