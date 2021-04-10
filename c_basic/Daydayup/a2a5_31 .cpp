#include<stdio.h>
#include<string.h>
int main() {
	char a[50000],e[50000];
	int i=0,j=1,k=0;
	scanf("%s",a);
	while(a[i]!='\0') {
		if(a[i+1]==a[i]) ++j;
		else  {
		e[k++]=a[i];
		e[k++]=j+48;
		 j=1;  }
		++i;
	}
	e[k]='\0';
	if(k<strlen(a)) printf("%s\n",e);
	else printf("%s\n",a);
	return 0;
}
