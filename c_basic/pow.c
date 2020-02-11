#include <stdio.h>
int main() {
    float x, pow1;
    int n, i;
    scanf("%f,%d", &x, &n);
    pow1 = x;
    for (i = 1; i < n; i++) pow1 = x * pow1;
    printf("%f", pow1);
    return 0;
}