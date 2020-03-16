#include <stdio.h>
// #include "Leap_year_sum.c"

void about_intelligence(int x1, int y1, int z1, int x2, int y2, int z2, int n);
void about_power(int x1, int y1, int z1, int x2, int y2, int z2, int n);
void about_mood(int x1, int y1, int z1, int x2, int y2, int z2, int n);
int leapyear_num(int year_start, int year_finally);

int main() {
    int year1, year2, moon1, moon2, day1, day2, n;  // n为闰年数

    printf("请输入你的出生年月日（如：2000，1，1)：");
    scanf("%d,%d,%d", &year1, &moon1, &day1);
    printf("请输入你想测的日期（格式同上）：");
    scanf("%d,%d,%d", &year2, &moon2, &day2);
    n = leapyear_num(year1, year2);
    printf("n = %d\n", n);
    printf("这天是：\n");
    about_intelligence(year1, moon1, day1, year2, moon2, day2, n);
    about_mood(year1, moon1, day1, year2, moon2, day2, n);
    about_power(year1, moon1, day1, year2, moon2, day2, n);
    return 0;
}

void about_intelligence(int x1, int y1, int z1, int x2, int y2, int z2, int n) {
    int num, sum;
    sum = (x2 - x1) * 365 + n - (y1 * 30 + z1) + (y2 * 30 + z2);
    num = sum % 33;
    if (num == 0)
        printf("智力周期日");
    else if (num < 17)
        printf("智力高潮日");
    else if (num == 17)
        printf("智力临界日");
    else
        printf("智力低潮期");
    printf("\n");
}

void about_power(int x1, int y1, int z1, int x2, int y2, int z2, int n) {
    int num, sum;
    sum = (x2 - x1) * 365 + n - (y1 * 30 + z1) + (y2 * 30 + z2);
    num = sum % 23;
    if (num == 0)
        printf("体力周期日");
    else if (num < 12)
        printf("体力高潮日");
    else if (num == 12)
        printf("体力临界日");
    else
        printf("体力低潮期");
    printf("\n");
}

void about_mood(int x1, int y1, int z1, int x2, int y2, int z2, int n) {
    int num, sum;
    sum = (x2 - x1) * 365 + n - (y1 * 30 + z1) + (y2 * 30 + z2);
    num = sum % 28;
    printf("%d",num);
    if (num == 0)
        printf("情绪周期日");
    else if (num < 14)
        printf("情绪高潮日");
    else if (num == 14)
        printf("情绪临界日");
    else
        printf("情绪低潮期");
    printf("\n");
}

int Leapyear(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int leapyear_num(int year_start, int year_finally) {
    int count = 0;
    for (int i = 0; i <= year_finally - year_start; i++) {
        if (Leapyear(year_start + i))
            count++;
    }
    return count;
}