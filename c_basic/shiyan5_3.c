#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	int i;
	int j=0;
	int k;
	int count = 0; int m=n;                     //����
	printf("�����벻������λ����������");
	scanf("%d",&n);                     //����������

//�������      
	printf("���������");
	for(i=1;i<=5;i++)              
	{
		j=n%10;                          //��β��
		n/=10;                           //ȥβ��
		count++;
		printf("%d",j);
		if(n==0)
		{
			break;
		}
	}
	printf("\n");

printf("λ��Ϊ%d\n",count);                  //���λ��

//˳�����
printf("˳�������");
	for(i;i>=1;i--)
	{
		k=m/(int)pow((float)10,(float)count-1);       //����λ
		m%=(int)pow((float)10,(float)count-1);
		count--;
		printf("%d",k);
	}

	printf("\n");
	
	return 0;
}