/*
 last updated: 2010/06/02 00:43:55
 */
#include <stdio.h>

int ok(int d) {
  int k[8] = {0,0,0,0,0,0,0,0};
  int u[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int p = 0;
  while (d > 0) {
    int i = d % 10;
    k[p] = i;
    if (u[i] != -1)
      return u[i];
    u[i] = p;
    p++;
    d = (d-i) / 10;
  }
  return -1;
}

int pown(int x, int n) {
  int ret = 1;
  while (n--)
    ret *= x;
  return ret;
}

int main(int argc, char *argv[]) {
  int n;
  while (scanf("%d", &n)) {
    if (n == 0) break;
    int ans = 0;
    while (n--) {
      ans++;
      int p;
      while ((p = ok(ans)) != -1)
        ans += pown(10, p);
    }
    printf("%d\n", ans);
  }
  return 0;
}
