#include <stdio.h>
int main ()
{int h;
float r,L,S1,S2,V1,V2;
double PI=3.141592;
	printf("请输入圆的半径：r=\n");
	printf("请输入圆柱的高：h=\n");
	scanf("%f%d",&r,&h);
	L=2*r*PI;
	S1=PI*r*r;
	S2=4*PI*r;
	V1=4/3*PI*r*r*r;
	V2=PI*r*r*h;
	printf("圆周长为:");
	printf("%3.2f\n",L);
	printf("圆面积为: ");
	printf("%3.2f\n",S1);
	printf("圆球表面积为: \n");
	printf("%3.2f\n",S2);
	printf("圆球体积为: \n");
	printf("%3.2f\n",V1);
	printf("圆柱体积为:\n");
	printf("%3.2f\n",V2);
}



