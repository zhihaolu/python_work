#include<stdio.h>
int main() {
    int a[3][3] = {{1,2,11},{4,5,12},{7,8,9}};

    int i,j;
    int maxInRow,maxColumn,raw;
    int minInColumn, tempRaw;
    for(i=0;i<3;i++){
        maxInRow = a[i][0];
        for(j=0;j<3;j++){
            if(maxInRow<=a[i][j]){
            maxInRow = a[i][j];
            maxColumn = j;
            raw = i;
            }
        }

    minInColumn = a[0][maxColumn];
        for(j=0;j<3;j++){
            if(minInColumn>=a[j][maxColumn]){
                minInColumn = a[j][maxColumn];
                tempRaw = j;
            }
        }
        if(raw == tempRaw){
              printf("第%d行%d列有鞍点%d\n", raw+1,maxColumn+1,a[raw][maxColumn]);
        }else{
            printf("第%d行没有鞍点\n",raw+1);
        }

    }

    return 0;
}
