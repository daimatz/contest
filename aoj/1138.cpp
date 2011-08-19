#include <cstdio>
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALLOF(c) (c).begin(), (c).end()
using namespace std;
const double eps = 10e-4;
int Ticket[8];
struct Edge {
  int to, d;
};
struct State {
  int v, t;
  double d;
  bool operator<(const State &s)const{
    return d>s.d;
  }
};
// hoge
vector<Edge> G[30];
double DP[30][1<<8];
pair<bool, double> Daijkstra(int s, int t, int n) {
  DP[s][(1<<n)-1]=0;
  priority_queue<State> pq;
  pq.push((State){s, (1<<n)-1, 0});
  while (!pq.empty()) {
    State cur = pq.top();
    pq.pop();
    if (cur.v == t)
      return pair<bool, double>(true, cur.d);
    if (DP[cur.v][cur.t]>cur.d)
      continue;
    REP(i, G[cur.v].size()) {
      REP(j, n) {
        if (!(cur.t & 1 << j))
          continue;
        double nd = DP[cur.v][cur.t]+1.0*G[cur.v][i].d/Ticket[j];
        if (DP[G[cur.v][i].to][cur.t & ~(1<<j)]-nd > eps) {
          DP[G[cur.v][i].to][cur.t & ~(1<<j)] = nd;
          pq.push((State){G[cur.v][i].to,cur.t & ~(1<<j),nd});
        }
      }
    }
  }
  return pair<bool, double>(false, 0);
}

int main() {
  vector<int> i;
  for (int n,m,p,a,b;scanf("%d%d%d%d%d", &n, &m, &p, &a, &b), n+m+p+a+b;) {
    REP(i,n) scanf("%d", Ticket+i);
    REP(i,m) G[i].clear();
    REP(i,m) {
      REP(j, 1<<n) DP[i][j] = INT_MAX/2;
    }
    REP(i,p) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      G[x-1].push_back((Edge){x-1,z});
      G[y-1].push_back((Edge){x-1,z});
    }
    pair<bool, double> res = Daijkstra(a-1, b-1, n);
    if (res.first) printf("%.3f\n", res.second);
    else printf("Impossible");
  }
  return 0;
}
