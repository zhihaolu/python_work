#include<stdio.h>
#include<string.h>

int main () 
{	char a[50002];
	char b[50002];
	char p;
	int i,j,cnt;
	scanf("%s",a);
	p=b[0]=a[0];
	for(i=1,cnt=1,j=0;i<=strlen(a);i++)
	{	if(p!=a[i])	
		{	b[2*j+1]=cnt+48;	
			j++;
			p=b[2*j]=a[i];	
			cnt=1;
		}
		else
			cnt++;
	}
	if(strlen(a)>strlen(b)) 
		printf("%s\n",b);
	else
		printf("%s\n",a);	 
}
