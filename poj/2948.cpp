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
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 500
#define MAX_M 500

struct P {
  int y,b;
};

P maze[MAX_N][MAX_M];
int n,m;

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
      break;
    REP(i, n) {
      REP(j, m) {
        maze[i][j] = (P){0,0};
      }
    }
    REP(i, n) {
      REP(j, m) {
        scanf("%d", &maze[i][j].y);
      }
    }
    REP(i, n) {
      REP(j, m) {
        scanf("%d", &maze[i][j].b);
      }
    }

    long long ans = 0;
    while (n > 0 && m > 0) {
      int up = 0, left = 0;
      REP(i, n) {
        up += maze[n-1-i][m-1].b;
      }
      REP(j, m) {
        left += maze[n-1][m-1-j].y;
      }
      if (up > left) {
        //DEBUG(up);
        ans += up;
        m--;
      } else {
        //EBUG(left);
        ans += left;
        n--;
      }
    }
    /**
     * REP(i, n) {
     *   REP(i, m) {
     *
     *   }
     * }
     */
    cout << ans << endl;
  }
  return 0;
}
