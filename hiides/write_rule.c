#include<stdio.h>
#include<string.h>
main( int argc, char *argv[] )
{
  int i,s,hex,p,l;
  char *ch,buff[255]={0};
  FILE *fp  ;
  char str[100],*temp1;
  fp=fopen("ruless.dat","a+");
  

for(i=1;i<3;i++)
{
  temp1=argv[i];
  ch=strtok(temp1,".");

  while(ch!=NULL)
  {
	  if(strlen(ch)==1)
		fprintf(fp,"%s","00");
	if(strlen(ch)==2)
	fprintf(fp,"%s","0");
    fprintf(fp,"%s",ch);
	ch = strtok (NULL, ".");
	
	  }
  }
  
  l=strlen(argv[3]);
  for(i=0;i<5-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[3]);
  l=strlen(argv[4]);
  for(i=0;i<5-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[4]);
  l=strlen(argv[5]);
  for(i=0;i<8-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[5]);
  l=strlen(argv[6]);
  for(i=0;i<2-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[6]);
  fprintf(fp,"%s",argv[7]);
  l=strlen(argv[8]);
  for(i=0;i<10-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[8]);
  l=strlen(argv[9]);
  for(i=0;i<10-l;i++)
  {
	  fprintf(fp,"%s","0");
  }
  fprintf(fp,"%s",argv[9]);
  fprintf(fp,"%s","\n");
  

	fclose(fp);
}
