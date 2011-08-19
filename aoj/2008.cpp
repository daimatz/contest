#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 20

typedef complex<double> P;

int n, hx, hy, dx, dy;
int dp[1<<MAX_N][MAX_N];
P c[MAX_N];

struct Edge {
  int from, to;
  double cost;
};
typedef vector< pair<int, vector<Edge> > > Graph;
Graph g(MAX_N);

void solve() {
  REP(i, 1<<n) {
    fill(dp[i], dp[i]+n, INF);
  }

  dp[(1<<n)-1][0] = 0;
  for (int S = (1<<n)-2; S >= 0; S--) {
    REP(v, n) {
      REP(u, n) {
        if (!(S>>u) & 1) {

        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d %d %d %d", &n, &hx, &hy, &dx, &dy);
    P h(hx,hy), d(dx,dy);
    if (n == 0) break;
    g.clear();
    REP(i, n) {
      int x,y;
      scanf("%d %d", &x, &y);
      c[i] = P(x,y);
    }

    REP(i, n) {
      g[i].first = abs(d-c[i]);
      REP(j, i) {
        g[i].second.push_back((Edge){i,j,abs(c[i]-c[j])});
        g[j].second.push_back((Edge){j,i,abs(c[i]-c[j])});
      }
    }

    solve();
  }
  return 0;
}
