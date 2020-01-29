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
	printf("最大公约数为：%d\n", b);
	printf("最小公倍数为:%d",m*n/b);
	return 0;
}
