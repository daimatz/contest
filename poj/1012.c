#include <stdio.h>

long long int execute(int k) {
  long long int m;
  int flag = 0;
  for (m = k + 1; flag == 0; ) {
    int n, exe = 0;
    for (n = 1; n <= k; n++) { /* k 客借泛に喇根すれば ok. */
      exe = ((exe-1)+m)%(2*k-n+1);
      if (0 <= exe && exe <= k-1) {/* 己窃 */
        n = -1;
        break;
      }
    }
    if (n != -1) return m; /* 喇根 */
    if (m % (k+1) == 0) m += 1;
    else m += k;
  }
}

int main(int argc, char *argv[]) {
  int k;
  long long int a[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  while (1) {
    if (scanf("%d\n", &k) != 1) return 1;
    if (k == 0) return 0;
    if (a[k] == -1)
      a[k] = execute(k);
    printf("%lld\n", a[k]);
  }
  return 0;
}
