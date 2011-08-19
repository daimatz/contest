#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

typedef struct {
  int p;
  int q;
} S;

int main(int argc, char *argv[]) {
  int i, j;
  double sum = 0.0;
  while (scanf("%d.%d", &i, &j) == 2) {
    sum += i + 0.01 * j;
  }
  printf("$%.2f\n", sum / 12);
  return 0;
}
