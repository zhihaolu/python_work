#include<stdio.h>
#include<string.h>
int main()
{
	char ch[50000],x[50000];
	int i=0,j=1,k=-1;
	scanf("%s",ch);
	while(i!=strlen(ch)) 
	{
		if(ch[i]!=ch[i+1])
		{
			x[++k]=ch[i];
			x[++k]=j+48;
			j=1;
		}
		else ++j;    ++i;
	}
	x[k+1]='\0';
	if(strlen(ch)>strlen(x)) 
		printf("%s",x);
	else	
		printf("%s",ch);
}
