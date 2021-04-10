#include<stdio.h>
int main() {
	int l,m;
	int u,v;
	int x,y;
	scanf("%d%d",&l,&m);
	while(m) {
	x=u;y=v;
	scanf("%d",&u);
	scanf("%d",&v);
	if(u<x&&v>x&&v<y) u=x+2;
		l-=(v-u+1);
		--m;
	}
	printf("%d\n",l);
	return 0;
}
