#include <stdio.h>
int main ()
{char c;
printf("ÇëÊäÈëÒ»¶Î×Ö·û:");
c=getchar();
while(c!='\n')
{
	if(c>='A'&&c<='V'||c>='a'&&c<='v') c=c+4;
else c=c=+4-26;
printf("%c",c);
c=getchar();
}
}



