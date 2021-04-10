/*
	字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
	若“压缩”后的字符串没有变短，则返回原先的字符串。
	你可以假设字符串中只包含大小写英文字母（a至z）
	①输入：aabcccccaaaa
	  输出：a2b1c5a3
	②输入：abbccd
	  输出：abbccd(因为压缩后a1b2c2d1比原字符还长)
	提示：字符串长度在[0,50000]范围内。
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char ch1[50000];
	char ch2[50000];
	int i=0;//ch1
	int j=1;//计数
	int k=0;//ch2
	scanf("%s",ch1);
	while(ch1[i]!='\0')
	{
		if(ch1[i]==ch1[i+1])//如果前后字母相等
			j++;
		else//如果前后字母不相等
		{
			ch2[k]=ch1[i];
			k++;
			ch2[k]=j+48;//不加48不行，0在ascll码表的序号是48
			k++;//↖这里可以用k++，二合一
			j=1;//重新开始计数
		}
		i++;
	}
	ch2[k]='\0';//不加就会很烫
	if(strlen(ch2)>i)
		printf("%s\n",ch1);
	else
		printf("%s\n",ch2);
	return 0;
}