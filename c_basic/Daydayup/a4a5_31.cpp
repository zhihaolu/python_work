#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j,n,m,s,d=0;
	char a[50000],b[50000],c;
	 scanf("%s",a);
	 n=strlen(a);
	 while(i<n-1)
	 {
	 	s=0;
	   b[d]=a[i];
	   while(b[d]==a[i]) 
	   {
	   	s++;
	   	i++;
	   }
	   d++;
	   b[d]=s+48;   
	   d++;
	 }
	 m=strlen(b);
	 if(n>m) printf("%s",b);
	 else printf("%s",a);
	 return 0;
 } 
