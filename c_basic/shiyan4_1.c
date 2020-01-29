#include<stdio.h>
#include<math.h>
int main()
{int n,i,k;
printf("请输入一个数:n=?");
scanf("%d",&n);
k=sqrt(n);
for(i=2;i<=k;i++)
if(n%i==0)break;
if(i<=k)printf("%d不是素数\n",n);
else printf("%d是素数\n",n);
return 0;
}