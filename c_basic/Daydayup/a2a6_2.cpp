#include<stdio.h>
int main()
{
	int n,h1,m1,s1,h2,m2,s2,h3,m3,s3;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&h1,&m1,&s1);
		scanf("%d%d%d",&h2,&m2,&s2);
		s3=(s1+s2)%60;
		m3=(m1+m2)%60+(s1+s2)/60;
		h3=h1+h2+(m1+m2)/60;
		printf("%d %d %d\n",h3,m3,s3);
	}	
} 
