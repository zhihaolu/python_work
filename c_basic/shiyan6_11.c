#include<stdio.h>
int main()
{int i,j,x,y,w,g,k;
char a[3][80];
x=y=w=g=k=0;
for(i=0;i<3;i++)
{printf("ÊäÈëÒ»ÐÐ×Ö·û:%d\n",i+1);
gets(a[i]);
for(j=0;j<=80 && a[i][j]!='\0';j++)
{if(a[i][j]>='A' && a[i][j]<='Z')
x++;
else if(a[i][j]>='a' && a[i][j]<='z')
 y++;
else if(a[i][j]>='0' && a[i][j]<='9')
 w++;
else if(a[i][j]==' ')
 g++;
else
 k++;}
}
printf("x:%d\n",x);
printf("y:%d\n",y);
printf("w:%d\n",w);
printf("g:%d\n",g);
printf("k:%d\n",k);
return 0;
}