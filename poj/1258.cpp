#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
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
#define DEBUG(x) cerr<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

int N;
int cost[100][100];

int prim() {
  int mincost[100];
  bool used[100];
  REP(i, N) {
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;

  while (1) {
    int v = -1;
    REP(u, N)
      if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    if (v == -1) break;
    used[v] = true;
    res += mincost[v];
    REP(u, N)
      mincost[u] = min(mincost[u], cost[v][u]);
  }
  return res;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (scanf("%d", &N) != EOF) {
    REP(i, N) REP(j, N) {
      scanf("%d", &cost[i][j]);
    }

    printf("%d\n", prim());
  }

  return 0;
}
