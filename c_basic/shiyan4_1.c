#include<stdio.h>
#include<math.h>
int main()
{int n,i,k;
printf("������һ����:n=?");
scanf("%d",&n);
k=sqrt(n);
for(i=2;i<=k;i++)
if(n%i==0)break;
if(i<=k)printf("%d��������\n",n);
else printf("%d������\n",n);
return 0;
}