#include <stdio.h>
int main() {
  float average(float array[], int n);
  float score1[51];
  float score2[51];
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%f", &score1[i]);
  for (i = 0; i < m; i++) scanf("%f", &score2[i]);
  printf("%2.2f %2.2f\n", average(score1, n), average(score2, m));
  return 0;
}

float average(float array[], int n) {
  int i;
  float aver, sum = array[0];
  for (i = 1; i < n; i++) sum = sum + array[i];
  aver = sum / n;
  return (aver);
}