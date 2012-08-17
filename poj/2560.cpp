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

typedef complex<double> Point;

struct Edge {
  int from, to;
  double cost;
};

int n;
vector<Point> v;

vector<Edge> G[110];

typedef pair<double, int> P;

double prim() {
  int visited[110];
  double ret = 0;
  int vis = 0;

  fill_n(visited, 110, false);
  priority_queue<P, vector<P>, greater<P> > q;
  q.push(P(0, 0));
  while (!q.empty()) {
    P p = q.top(); q.pop();
    int pos = p.second;
    if (visited[pos]) continue;
    visited[pos] = true;
    ++vis;
    ret += p.first;
    if (vis == n) return ret;
    REP(i, G[pos].size()) {
      if (!visited[G[pos][i].to]) {
        q.push(P(G[pos][i].cost, G[pos][i].to));
      }
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d", &n);
  REP(i, n) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    v.push_back(Point(x, y));
  }

  REP(i, v.size()) {
    vector<Edge> tmp;
    REP(j, v.size()) {
      if (i != j) {
        Edge e = (Edge){i,j,abs(v[i]-v[j])};
        tmp.push_back(e);
        //DEBUG(e.from); DEBUG(e.to); DEBUG(e.cost);
      }
    }
    G[i] = tmp;
  }

  printf("%.2f\n", prim());

  return 0;
}
