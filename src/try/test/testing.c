#include<stdio.h>
void todec(char ch[])
{
	int l;
	l=strlen(ch);
	printf("%d",l);
}
void main()
{
	char ch[]="11111111111111111";
	todec(ch);
}
