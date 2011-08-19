#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979

float r2(int n) {
  return 100.0 * (((float)n) / PI);
}

float d2(float x, float y) {
  return (x*x + y*y);
}

int main(int argc, char *argv[]) {
  int n, i, j;
  if (scanf("%d", &n) != 1)
    return 1;
  for (i = 0; i < n; i++) {
    float x, y;
    if (scanf("%f %f", &x, &y) != 2)
      return 1;
    for (j = 0; ; j++) {
      if (d2(x, y) <= r2(j)) {
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, j);
        break;
      }
    }
  }
  printf("END OF OUTPUT.\n");
  return 0;
}
