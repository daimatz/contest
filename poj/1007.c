#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define M 100

int score(const char *t, int len) {
  char s[len+1];
  int cnt = 0, i = 0;
  strncpy(s, t, len+1);
  while (len > 0) {
    if (i < len) {
      if (s[i] > s[i+1]) {
        /* s[i] と s[i+1] を swap */
        char q;
        q = s[i];
        s[i] = s[i+1];
        s[i+1] = q;
        /* カウントアップ */
        cnt++;
      }
      i++;
    } else {
      i = 0;
      len--;
    }
  }
  return cnt;
}

int compare(const char *a, const char *b) {
  int as, bs;
  as = score(a, strlen(a));
  bs = score(b, strlen(b));
  if (as > bs) return 1;
  if (as < bs) return -1;
  return 0;
}

int main(int argc, char *argv[]) {
  char buf[N+2];
  int n, m, i = 0;
  if (scanf("%d %d\n", &n, &m) != 2)
    return 1;
  char v[m][n+1];
  while (fgets(buf, N+2, stdin) != NULL) {
    if (strncpy(v[i], buf, n+1) < 0)
      return 1;
    v[i][n] = '\0';
    i++;
  }
  qsort(v, m, sizeof(char)*(n+1), (int(*)(const void*, const void*))compare);
  for (i = 0; i < m; i++) {
    printf("%s\n", v[i]);
  }
  return 0;
}
