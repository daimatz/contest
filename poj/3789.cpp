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
int h, m, s;


int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int k = 1; k <= n; k++) {
    int ver[6][3], hor[3][6];

    scanf("%d:%d:%d", &h, &m, &s);
    for (int i = 0; i < 6; i++) {
      if ((1<<i) & h) {
        ver[i][0] = hor[0][i] = 1;
      } else {
        ver[i][0] = hor[0][i] = 0;
      }
      if ((1<<i) & m) {
        ver[i][1] = hor[1][i] = 1;
      } else {
        ver[i][1] = hor[1][i] = 0;
      }
      if ((1<<i) & s) {
        ver[i][2] = hor[2][i] = 1;
      } else {
        ver[i][2] = hor[2][i] = 0;
      }
    }

    printf("%d ", k);
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 3; j++) {
        printf("%d", ver[5-i][j]);
      }
    printf(" ");
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 6; j++) {
        printf("%d", hor[i][5-j]);
      }
    printf("\n");
  }
  return 0;
}
