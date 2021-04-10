#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str1[5000], str2[5000];
	int a[5000] = {0}, i = 0, j = 0;
	cin >> str1;//str1ÎªÔ­×Ö·û´®
	str2[0] = str1[0];
	while(str1[i+1] != '\0')
	{
		if(str1[i] == str1[i+1])
			a[j]++;
		else
			str2[++j] = str1[i+1];
		i++;
	}
    j++;
	if(i+1 > 2*j)
		for(int k = 0; k < j; k++)
			cout << str2[k] << a[k]+1;
	else
		cout << str1;
}
