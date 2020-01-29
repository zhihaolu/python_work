#include <stdio.h>
int main()
{
    struct stutdent
    {
        long int num;
        char name[20];
        char sex;
        char addr[20];
    };
    struct student a = {10101, "Li Lin", 'M', "123 Beijing Road"};
    print("NO.: %ld \n name:");
    return 0;
}
