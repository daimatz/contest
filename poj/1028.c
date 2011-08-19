#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define URL_MAX 70
#define STACK_MAX 100

int main(int argc, char *argv[]) {
  char cmd[URL_MAX+10];
  char b[100][URL_MAX+1], f[100][URL_MAX+1];
  int bi = 0, fi = 0;
  char url[URL_MAX+1];
  strcpy(url, "http://www.acm.org/");
  while (1) {
    char *c, *u;
    if (fgets(cmd, URL_MAX+10, stdin) == NULL)
      return 1;
    c = strtok(cmd, " \n");
    u = strtok(NULL, " \n");
    if (strcmp(c, "VISIT") == 0) { /* VISIT */
      if (u == NULL)
        return 1;
      fi = 0;
      strcpy(b[bi++], url);
      strcpy(url, u);
      printf("%s\n", u);
    } else if (strcmp(c, "BACK") == 0) { /* BACK */
      if (u != NULL)
        return 1;
      if (bi == 0) {
        printf("Ignored\n");
      } else {
        strcpy(f[fi++], url);
        strcpy(url, b[--bi]);
        printf("%s\n", url);
      }
    } else if (strcmp(c, "FORWARD") == 0) { /* FORWARD */
      if (u != NULL)
        return 1;
      if (fi == 0) {
        printf("Ignored\n");
      } else {
        strcpy(b[bi++], url);
        strcpy(url, f[--fi]);
        printf("%s\n", url);
      }
    } else if (strcmp(c, "QUIT") == 0) { /* QUIT */
      if (u != NULL)
        return 1;
      return 0;
    } else {
      return 1;
    }
  }
  return 0;
}
