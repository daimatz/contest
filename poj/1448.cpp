#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(typeof(n) i = 0; i < (n); i++)
using namespace std;

#define INF (INT_MAX/10-1)

int n;
int men[6][6][6];
int hen[6][4][6];

bool match(int hen1[6], hen2[6]) {
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int N = 0; N < n; N++) {

    bool ok = false;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 6; k++) {
          char tmp;
          scanf(" %c", &tmp);
          men[j][i][k] = (tmp == 'X' ? 1 : 0);
        }
        char t;
        scanf("%c", &t);
      }
    }

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        hen[i][0][j] = men[i][0][j];
        hen[i][1][j] = men[i][j][5];
        hen[i][2][j] = men[i][5][5-j];
        hen[i][3][j] = men[i][0][5-j];
      }
    }

    int a[] = {1,2,3,4,5};
    do {
      int j = 1;
      for (int i = 0; i < 4; i++) {
        if (match(hen[0][0], hen[j][i])) {
          j++;
        }
      }
    } while (next_permutation(a, a+5));

    /**
     * REP(i,6) {
     *   REP(j,6) {
     *     REP(k, 6) {
     *       printf("%c", men[i][j][k]);
     *     }
     *     printf("\n");
     *   }
     *   printf("\n");
     * }
     */


    printf("Scenario #%d:\n", N+1);
    if (ok)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
