#include<stdio.h>
int main()
{int n;
scanf("%f",&n);
if(n>=90)
printf("A");
else
if(n<=89&&n>=80)
printf("B");
else
if(n<=79&&n>=70)
printf("C");
else
if(n<=69&&n>=60)
printf("D");
else
if(n<60)
printf("E");
return 0;
}