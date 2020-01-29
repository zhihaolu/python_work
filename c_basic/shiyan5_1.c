#include<stdio.h>
#include<math.h>
int main()
{int year;
printf("请输入一个年份:\n");
scanf("%d",&year);
printf("这是个闰年:\n");
if(year%4==0)
printf("yes\n");
else 
printf("no");
return 0;
}