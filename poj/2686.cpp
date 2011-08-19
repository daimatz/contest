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

#define MAX_N 8
#define MAX_M 30
int n,m,a,b;
int t[MAX_N];
int d[MAX_M][MAX_M];

double dp[1<<MAX_N][MAX_M];

void solve() {
  for (int i = 0; i < 1<<n; i++)
    for (int j = 0; j < m; j++)
      dp[i][j] = INF;

  dp[(1<<n)-1][a-1] = 0;
  double res = INF;
  for (int S = (1<<n)-1; S >= 0; S--) {
    res = min(res, dp[S][b-1]);
    for (int v = 0; v < m; v++) {
      for (int i = 0; i < n; i++) {
        if (S & (1 << i)) {
          for (int u = 0; u < m; u++) {
            if (d[v][u] >= 0) {
              dp[S & ~(1<<i)][u] = min(dp[S & ~(1<<i)][u], dp[S][v] + (double)d[v][u] / t[i]);
            }
          }
        }
      }
    }
  }

  if (res == INF)
    printf("Impossible\n");
  else
    printf("%.3f\n", res);
}

int main(int argc, char *argv[]) {
  while (1) {
    int p;
    scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
    if (m == 0)
      break;
    memset(d, -1, sizeof(d));
    REP(i, n) {
      scanf("%d", t+i);
    }
    REP(i, p) {
      int x,y,z;
      scanf("%d %d %d", &x, &y, &z);
      d[x][y] = d[y][x] = z;
    }

    solve();
  }

  return 0;
}
