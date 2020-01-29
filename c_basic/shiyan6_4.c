#include<stdio.h>//7.10 有一篇文章，共有3行文字，每行有80个字符。要求分别统计出其中英文大写字母、小写字母、数字、空格以及其他字符的个数。
int main()
{
	char c[3][80];
	int i,j,daxie=0,xiaoxie=0,shuzi=0,kongge=0,qita=0;
	printf("请输入第1行：\n");
	gets(c[0]);
	puts(c[0]);
	
	printf("请输入第2行：\n");
	gets(c[1]);
	puts(c[1]);
	
	printf("请输入第3行：\n");
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
	printf("大写：%d\n小写：%d\n数字：%d\n空格：%d\n其他：%d\n",daxie,xiaoxie,shuzi,kongge,qita);
	return 0;
}
