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

int N, m;

struct Edge {
  int to, cost;
};

vector<vector<Edge> > Graph;
// COST[from][to][via];
int COST[10][10][10];

struct State {
  int path;
  int cost;
  int pos;
  bool operator<(const State &a) const {
    return cost > a.cost;
  }
  void print() {
    printf("pos: %d;; path: ", pos);
    REP(i, N) if (path&(1<<i)) printf("%d ", i);
    printf(";; cost: %d\n", cost);
  }
};

bool used[10][1<<10];

int dijkstra() {
  priority_queue<State> q;
  q.push((State){0, 0, 0});
  while (!q.empty()) {
    State p = q.top(); q.pop();
    //p.print();
    if (p.pos == N) return p.cost;
    if (used[p.pos][p.path]) continue;
    used[p.pos][p.path] = true;

    int from = p.pos;

    REP(i, Graph[from].size()) {
      Edge e = Graph[from][i];
      int to = e.to;
      int npath = p.path;
      npath = p.path | (1<<to);

      int minc = INF;

      //DEBUG(to);
      REP(i, N) {
        if (p.path & (1<<i)) {
          int via = i;
          minc = min(minc, COST[from][to][via]);
        }
      }
      //DEBUG(minc); DEBUG(e.cost);
      State nstate = (State){npath, p.cost+min(e.cost, minc), to};
      q.push(nstate);
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 10) REP(j, 10) REP(k, 10) COST[i][j][k] = INF;

  scanf("%d%d", &N, &m);
  Graph.resize(N);
  REP(i, N) Graph[i] = vector<Edge>();
  --N;
  int a, b, c, P, R;
  REP(i, m) {
    scanf("%d%d%d%d%d", &a, &b, &c, &P, &R);
    --a; --b; --c;
    Graph[a].push_back((Edge) {b, R});
    COST[a][b][c] = P;
  }

  int ans = dijkstra();
  if (ans == -1) puts("impossible");
  else printf("%d\n", ans);

  return 0;
}
