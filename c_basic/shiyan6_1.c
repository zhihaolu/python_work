#include<stdio.h>
int main()
{int a[10]={1,3,4,5,6,7,8,9,10};
int k,i=0,j=0;
scanf("%d",&k);
for(i=8;i>=0;i--)
{if(k<a[i])
{a[i+1]=a[i];}
else{a[i+1]=k;
break;
}
}
for(i=0;i<10;i++)
{printf("%d\t",a[i]);}
printf("pause");
return 0;
}