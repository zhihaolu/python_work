#include<stdio.h>
int main()
{
	int l,m,x,y,i;
	scanf("%d%d",&l,&m);
	int t[l+1]={0};
	while(m--)
	{
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
				t[i]=1;
	}
	for(i=0;i<=l;i++)
		if(t[i]==0)
			m++;
	printf("%d\n",m+1);	
}
