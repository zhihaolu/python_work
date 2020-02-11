#include<stdio.h>

int Leapyear(int year);
int leapyear_num(int year_start, int year_finally);

int main() {
    int start_year, end_year;
    printf("input start_year and end_year: ");
    scanf("%d,%d", &start_year, &end_year);
    printf("leapyear_num: %d \n", leapyear_num(start_year, end_year));
    return 0;
}

int Leapyear(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int leapyear_num(int year_start, int year_finally) {
    int count = 0;
    // for (int i = 0; i <= year_finally - year_start; i++) {
    //     if (Leapyear(year_start + i))
    //         count++;
    // }

    int i = year_start;
    while (i <= year_finally) {
        if (Leapyear(i)) {
            count ++;
            i += 4;
        } else {
            i++;
        }
    }
    return count;
}