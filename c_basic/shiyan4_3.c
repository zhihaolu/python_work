#include <stdio.h>
int main()
{
	int a,b;
	int y;
	int m,n;
	printf("input two numbers:\n");
	scanf("%d,%d", &m, &n);
	a = m;
	b= n;
	while (a%b != 0)
	{
		y = a%b;
		a = b;
		b = y;
	 }
	printf("���Լ��Ϊ��%d\n", b);
	printf("��С������Ϊ:%d",m*n/b);
	return 0;
}
