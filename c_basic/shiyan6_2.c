#include<stdio.h>
int main()
{int min,a[11],i,j,k;
printf("enter data:\n");
for(i=1;i<=10;i++)
{printf("a[%d]=",i);
scanf("%d",&a[i]);
}
printf("\n");
printf("Ô­Ë³Ğò:\n");
for(i=1;i<=10;i++)
printf("%5d",a[i]);
printf("\n");
for(i=1;i<=9;i++)
{min=i;
for(j=i+1;j<=10;j++)
if(a[min]>a[j])min=j;
k=a[i];a[i]=a[min];a[min]=k;}
printf("\nĞÂË³Ğò:\n");
for(i=1;i<=10;i++)
printf("%5d",a[i]);
printf("\n");
return 0;
}