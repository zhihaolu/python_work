#include<stdio.h>//7.10 ��һƪ���£�����3�����֣�ÿ����80���ַ���Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д��ĸ��Сд��ĸ�����֡��ո��Լ������ַ��ĸ�����
int main()
{
	char c[3][80];
	int i,j,daxie=0,xiaoxie=0,shuzi=0,kongge=0,qita=0;
	printf("�������1�У�\n");
	gets(c[0]);
	puts(c[0]);
	
	printf("�������2�У�\n");
	gets(c[1]);
	puts(c[1]);
	
	printf("�������3�У�\n");
	gets(c[2]);
	puts(c[2]);
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<8&&c[i][j]!='\0';j++)
		{
			if(c[i][j]==' ')kongge++;
			else if((c[i][j]>='0')&&(c[i][j]<='9'))shuzi++;
			else if((c[i][j]>='A')&&(c[i][j]<='Z'))daxie++;
			else if((c[i][j]>='a')&&(c[i][j]<='z'))xiaoxie++;
			else qita++;						
		}
	}
	printf("��д��%d\nСд��%d\n���֣�%d\n�ո�%d\n������%d\n",daxie,xiaoxie,shuzi,kongge,qita);
	return 0;
}
