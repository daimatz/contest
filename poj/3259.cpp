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

struct Edge {
  int from, to, cost;
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  Edge() {}
};

int N, M, W;
int d[600];

Edge e[6000];
int en;

void solve() {
  memset(d, 0, sizeof(d));
  REP(i, N) {
    REP(j, en) {
      if (d[e[j].to] > d[e[j].from] + e[j].cost) {
        d[e[j].to] = d[e[j].from] + e[j].cost;
        if (i == N-1) {
          puts("YES");
          return;
        }
      }
    }
  }
  puts("NO");
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int F;
  scanf("%d", &F);
  REP(i, F) {
    scanf("%d%d%d", &N, &M, &W);
    en = 0;
    REP(j, M) {
      int from, to, cost;
      scanf("%d%d%d", &from, &to, &cost);
      --from; --to;
      e[en++] = Edge(from, to, cost);
      e[en++] = Edge(to, from, cost);
    }
    REP(j, W) {
      int from, to, cost;
      scanf("%d%d%d", &from, &to, &cost);
      --from; --to;
      e[en++] = Edge(from, to, -cost);
    }
    solve();
  }

  return 0;
}
