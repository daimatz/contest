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
  int to, cost;
};

vector<Edge> G1[1000], G2[1000];

typedef pair<int, int> P;

int N, M, X;
int ans;

int d1[1000], d2[1000];

void dijkstra(vector<Edge> G[], int d[], int s) {
  REP(i, N) d[i] = INF;
  d[s] = 0;

  priority_queue<P, vector<P >, greater<P> > q;
  q.push(make_pair(0, s));

  while (!q.empty()) {
    P p = q.top(); q.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    REP(i, G[v].size()) {
      Edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        q.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d%d", &N, &M, &X);
  --X;
  REP(i, N) G1[i] = G2[i] = vector<Edge>();
  REP(i, M) {
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    --from; --to;
    G1[from].push_back({to,cost});
    G2[to].push_back({from,cost});
  }

  dijkstra(G1, d1, X);
  dijkstra(G2, d2, X);

  ans = 0;
  REP(i, N) {
    if (i != X)
      ans = max(ans, d1[i] + d2[i]);
  }
  printf("%d\n", ans);

  return 0;
}
