#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s1[55000],s2[55000];
	scanf("%s",s1);
	int len1=strlen(s1);
	int k=1,len2=0;
	for (int i=1; i<len1; i++)
	{
		if (s1[i]==s1[i-1]) k++;
		else 
		{	
			s2[len2++]=s1[i-1];
			s2[len2++]=k+'0';
			k=1;
		}		
	}
	s2[len2++]=s1[len1-1]; 
	s2[len2++]=k+'0';
	s2[len2]='\0';
	if (len1>len2) printf("%s\n",s2);
	else printf("%s\n",s1);
	return 0;
}
