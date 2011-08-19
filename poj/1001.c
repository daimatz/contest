#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512
#define toint(c) ((c)-48) /* '0' -> 0, '1' -> 1, ... */
#define tochr(n) ((n)+48) /* 0 -> '0', 1 -> '1', ... */

int start_pos(char *s) {
  int i = 0;
  while (*(s+i) == '0') {
    i++;
  }
  return i;
}

void padding(char *p, char *r) {
  int len, i;
  len = strlen(p);
  for (i = 0; i < MAX - len; i++) {
    *(r+i) = '0';
  }
  for (i = 0; i < len; i++) {
    *(r+MAX-1-i) = *(p+len-1-i);
  }
  *(r+MAX) = '\0';
}

void tochr2(int n, char *r) {
  *(r+MAX-1) = tochr(n % 10);
  *(r+MAX-2) = tochr((n - (n%10)) / 10);
}

void plus_chr(char p, char q, char *r) {
  tochr2(toint(p)+toint(q), r);
}

void multi_chr(char p, char q, char *r) {
  tochr2(toint(p)*toint(q), r);
}

void multi10(char *p) {
  while (*(p+1) == '0')
    p++;
  while (*(p+1) != '\0') {
    *p = *(p+1);
    p++;
  }
  *p = '0';
  *(p+1) = '\0';
}

void plus_str(char *p, char *q, char *r) {
  char *pp, *qp, *rp;
  pp = p + MAX - 1, qp = q + MAX - 1, rp = r + MAX - 1;
  while (1) {
    int n = toint(*pp)+toint(*qp)+toint(*rp);
    int flag = 0;
    if (n >= 10) {
      n -= 10;
      flag = 1;
    }
    *rp = tochr(n);
    if (rp != r) {
      *(rp-1) = tochr(flag);
    } else {
      break;
    }
    pp--;
    qp--;
    rp--;
  }
}

void multi_str(char *p, char *q, char *r) {
  char *pp, *qp, *rp;
  int i = 0, j = 0;
  int ps, qs;
  pp = p + MAX -1, qp = q + MAX - 1, rp = r + MAX - 1;
  ps = start_pos(p);
  qs = start_pos(q);
  while (qp != q+qs-1) {
    while (pp != p+ps-1) {
      char tmp1[MAX+1], tmp2[MAX+1];
      int k;
      padding("0", tmp1);
      padding("0", tmp2);
      multi_chr(*pp, *qp, tmp1);
      for (k = 0; k < i+j; k++) {
        multi10(tmp1);
      }
      plus_str(tmp1, r, tmp2);
      strncpy(r, tmp2, MAX+1);
      pp--;
      i++;
    }
    qp--;
    j++;
    pp = p + MAX - 1;
    i = 0;
  }
}

void print(char *s, int point) {
  int i, len;
  while (*s == '0')
    s++;
  len = strlen(s) - point;
  if (len <= 0) {
    printf(".");
    for (i = 0; i < -len; i++) {
      printf("0");
    }
  } else {
    for (i = 0; i < len; i++) {
      printf("%c", *s);
      s++;
    }
    if (point != 0)
      printf(".");
  }
  printf("%s\n", s);
}

int main(int argc, char *argv[]) {
  char buf[7];
  int n, i;
  while (scanf("%s%d", buf, &n) == 2) {
    int point = 0;
    char p[MAX+1], q[MAX+1], r[MAX+1];
    char tmp[7];
    int j = 0;
    /* abc.de の形の小数を abcde にして、小数点の位置を保存する */
    for (i = 0; i < strlen(buf); i++) {
      if ('0' <= buf[i] && buf[i] <= '9')
        tmp[j++] = buf[i];
      else if (buf[i] == '.')
        point = i;
    }
    tmp[j] = '\0'; /* tmp は 'a' 'b' 'c' 'd' 'e' '\0' */
    /* 小数点の位置が 0 でないなら */
    if (point != 0) {
      /* tmp を後ろから調べて、 0 がいたらそれを消す
         (1.2300 を 1.23 にする) */
      for (i = strlen(tmp)-1; i >= 0; i--) {
        if (tmp[i] != '0')
          break;
        else
          tmp[i] = '\0';
      }
      if (strlen(tmp) == 0)
        tmp[0] = '0';
      /* 小数点を後ろから数えた位置にする */
      point = strlen(tmp) - point;
    }
    padding(tmp, p);
    padding(tmp, r);
    for (i = 0; i < n-1; i++) {
      char tmp[MAX+1];
      strncpy(q, r, MAX+1);
      padding("0", tmp);
      multi_str(p, q, tmp);
      strncpy(r, tmp, MAX+1);
    }
    print(r, point * n);
  }
  return 0;
}
