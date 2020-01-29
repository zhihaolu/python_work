#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int i;
	int j=0;
	int k;
	int count = 0; int m=n;                     //计数
	printf("请输入不多于五位的正整数：");
	scanf("%d",&n);                     //输入正整数

//逆序输出      
	printf("逆序输出：");
	for(i=1;i<=5;i++)              
	{
		j=n%10;                          //得尾数
		n/=10;                           //去尾数
		count++;
		printf("%d",j);
		if(n==0)
		{
			break;
		}
	}
	printf("\n");

printf("位数为%d\n",count);                  //输出位数

//顺序输出
printf("顺序输出：");
	for(i;i>=1;i--)
	{
		k=m/(int)pow((float)10,(float)count-1);       //得首位
		m%=(int)pow((float)10,(float)count-1);
		count--;
		printf("%d",k);
	}

	printf("\n");
	
	return 0;
}