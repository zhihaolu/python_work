#include <stdio.h>
int main ()
{int h;
float r,L,S1,S2,V1,V2;
double PI=3.141592;
	printf("������Բ�İ뾶��r=\n");
	printf("������Բ���ĸߣ�h=\n");
	scanf("%f%d",&r,&h);
	L=2*r*PI;
	S1=PI*r*r;
	S2=4*PI*r;
	V1=4/3*PI*r*r*r;
	V2=PI*r*r*h;
	printf("Բ�ܳ�Ϊ:");
	printf("%3.2f\n",L);
	printf("Բ���Ϊ: ");
	printf("%3.2f\n",S1);
	printf("Բ������Ϊ: \n");
	printf("%3.2f\n",S2);
	printf("Բ�����Ϊ: \n");
	printf("%3.2f\n",V1);
	printf("Բ�����Ϊ:\n");
	printf("%3.2f\n",V2);
}



