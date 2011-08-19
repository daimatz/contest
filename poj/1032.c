#include <stdio.h>

int group_num(int n) {
  int k = 2;
  while ((k-1)*(k+6)/2+4 < n) {
    k++;
  }
  return k;
}

int f(int n, int k, int floor, int x[], int j) {
  int i, m = 0;
  if (k == 1) {
    if (n <= floor)
      return 0;
    x[j] = n;
    return n;
  }
  for (i = floor + 1; i < n; i++) {
    int tmp;
    tmp = i * f(n-i, k-1, i, x, j+1);
    if (tmp > m) {
      x[j] = i;
      m = tmp;
    }
  }
  return m;
}
int main(int argc, char *argv[]) {
  int n, k, i;
  if (scanf("%d", &n) != 1)
    return 1;
  k = group_num(n);
  int x[k];
  f(n, k, 1, x, 0);
  for (i = 0; i < k; i++)
    printf(((i+1 < k) ? "%d " : "%d\n"), x[i]);
  return 0;
}
