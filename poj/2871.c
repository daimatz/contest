/*
 last updated: 2010/06/02 02:42:55
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  float a, b;
  scanf("%f", &a);
  while (scanf("%f", &b)) {
    if (b > (double) 200)
      break;
    printf("%.2f\n", b-a);
    a = b;
  }
  printf("End of Output\n");
  return 0;
}
