#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 280

int main(int argc, char *argv[]) {
  char buf[8];
  while ((fgets(buf, 7, stdin)) != NULL) {
    double len = atof(buf) + 1.0;
    int i;
    double sum = 0.0;
    for (i = 0; i <= MAX; i++) {
      sum += 1.0 / (i+1);
      if (sum >= len) {
        if (i != 0)
          printf("%d card(s)\n", i);
        break;
      }
    }
  }
  return 0;
}
