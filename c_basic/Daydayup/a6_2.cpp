#include<stdio.h>

int main(){
    int i, j, AH, AM, AS, BH, BM, BS, H, M, S;
    scanf("%d", &i);
    for(j = 0; j < i; j++){
        scanf("%d%d%d%d%d%d", &AH, &AM, &AS, &BH, &BM, &BS);
        S = (AS + BS) % 60;
        M = (AM + BM + (AS + BS) / 60) % 60 ;
        H = (AH + BH) + (AM + BM + (AS + BS) / 60) / 60;
        printf("%d %d %d/n", H, M, S);
    }
    return 0;

}