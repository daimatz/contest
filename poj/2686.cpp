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
  Edge(int to, int cost) : to(to), cost(cost) {}

};

vector<Edge> Edges[30];

int N, M, P, A, B;
int ticket[8];
//int edge[30][30];
int S;
double dist[30][1<<8];

struct State {
  int now;
  double cost;
  int ticket;
  State(int now, double cost, int ticket) : now(now), cost(cost), ticket(ticket) {}
  bool operator<(const State &a) const {
    return cost > a.cost;
  };
};

void dijkstra() {
  REP(i, M) REP(j, 1<<8) dist[i][j] = INF;
  priority_queue<State> q;
  S = (1<<N)-1;
  q.push(State(A, 0, S));
  while (!q.empty()) {
    const State p = q.top(); q.pop();
    if (p.cost >= dist[p.now][p.ticket] - EPS) continue;
    //cerr << "now: " << p.now << ", cost: " << p.cost << ", ticket: " << p.ticket << endl;
    if (p.now == B) {
      printf("%.5f\n", p.cost);
      return;
    }
    dist[p.now][p.ticket] = p.cost;
    REP(i, N) {
      if ((1<<i) & p.ticket) {
        FOR(j, Edges[p.now]) {
          const int nticket = p.ticket & ~(1<<i);
          const double ncost = p.cost + static_cast<double>(j->cost)/ticket[i];
          if (dist[j->to][nticket] > ncost) {
            q.push(State(j->to, ncost, nticket));
          }
        }
      }
    }
  }
  puts("Impossible");
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    scanf("%d%d%d%d%d", &N, &M, &P, &A, &B);
    if (N+M+P+A+B == 0) break;
    --A; --B;
    REP(i, N) scanf("%d", ticket+i);
    REP(i, M) Edges[i].clear();
    REP(i, P) {
      int from, to, cost;
      scanf("%d%d%d", &from, &to, &cost);
      --from; --to;
      Edges[from].push_back(Edge(to,cost));
      Edges[to].push_back(Edge(from,cost));
      //edge[from][to] = edge[to][from] = cost;
    }
    dijkstra();
  }

  return 0;
}
