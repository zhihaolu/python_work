#include<stdio.h>
int main()
{int p;
float r,n,d;
printf("请输入年利率:\n存款年数:\n本金:\n");
scanf("%f%d%d",r,n,d);
p=d*(1+n*r);
printf("%f",p);
return 0;
}