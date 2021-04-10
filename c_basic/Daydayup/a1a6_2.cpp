#include<stdio.h>
int main()
{int N,i;
int a1,a2,a3,b1,b2,b3;
int h,m,s;
scanf("%d",&N);
while(N)
{
scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
s=(a3+b3)%60;
m=(a2+b2+(a3+b3)/60)%60;
h=a1+b1+(a2+b2+(a3+b3)/60)/60;
printf("%d %d %d\n",h,m,s); 
--N;
}
return 0;
 } 
