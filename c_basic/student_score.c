#include <stdio.h>
#define STUDENT 50
struct score {
  long int number;
  char name[5];
  struct subject three;
};
struct subject {
  float chinese;
  float math;
  float english;
};

int main() {
  struct score class1[STUDENT];
  int i, j, k;
  printf(
      "please key your number,name and your chinese, math, english,score in:");
  for (i = 0; i <= STUDENT; i++) scanf("%ld", &class1[i].number);
  for (i = 0; i <= STUDENT; i++) scanf("%s", &class1[i].name);
  for (i = 0; i <= STUDENT; i++)
    scanf("%f%f%f", &class1[i].three.chinese, &class1[i].three.math,
          &class1[i].three.english);
}

float aveage(float x, float y, float z) {
  float sum, ave;
  sum = x + y + z;
  ave = sum / 3;
  return sum;
}

void compare() {
  
}
