#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
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

#define MAX_N 1000

struct Edge {
  int to;
  double cost;
  bool operator<(const Edge &e) const {
    return cost > e.cost;
  }
};
vector<vector<Edge> > G;

struct In {
  int x, y, t, r;
};

inline int sq(int x) {
  return x*x;
}

int N;
double d[MAX_N];

typedef pair<double,int> P;

void dijkstra() {
  fill(d, d+N, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P> > q;
  q.push(make_pair(0,0));
  while (!q.empty()) {
    P p = q.top(); q.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    REP(i, G[v].size()) {
      Edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(int argc, char *argv[]) {

  scanf("%d", &N);
  G.resize(N);
  vector<In> in;
  REP(i, N) {
    int x, y, t, r;
    scanf("%d%d%d%d", &x, &y, &t, &r);
    in.push_back((In){x,y,t,r});
  }
  REP(i, N) {
    vector<Edge> es;
    REP(j, N) {
      if (i == j) continue;
      double d = sqrt(sq(in[i].x-in[j].x) + sq(in[i].y-in[j].y));
      int speed = min(in[i].t, in[j].r);
      es.push_back((Edge){j,d/speed});
    }
    G[i] = es;
  }

  dijkstra();

  sort(d, d+N);
  double ans = 0;
  REP(i, N) if (i != 0) ans = max(ans, d[i] + N - i - 1);
  printf("%.6f\n", ans);

  return 0;
}
