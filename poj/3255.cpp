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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(typeof(n) i = 0; i < (n); i++)
using namespace std;

#define INF (INT_MAX/10-1)

#define MAX_R 100000
#define MAX_N 5000
int N, R;

typedef pair<int, int> Pii;

struct Edge {
  int from, to, cost;
};
vector<Edge> G[MAX_N];
int d1[MAX_N];
int d2[MAX_N];

void dijkstra() {
  priority_queue<Pii, vector<Pii>, greater<Pii> > q;
  REP(i, N) {
    d1[i] = d2[i] = INF;
  }
  d1[0] = 0;
  q.push(Pii(0,0));

  while (!q.empty()) {
    Pii p = q.top(); q.pop();
    int v = p.second, d = p.first;
    if (d2[v] < d)
      continue;
    REP(i, G[v].size()) {
      Edge e = G[v][i];
      int tmp = d+e.cost;
      if (d1[e.to] > tmp) {
        swap(d1[e.to], tmp);
        q.push(Pii(d1[e.to], e.to));
      }
      if (d2[e.to] > tmp && d1[e.to] < tmp) {
        d2[e.to] = tmp;
        q.push(Pii(d2[e.to], e.to));
      }
    }
  }
  cout << d2[N-1] << endl;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &R);
  REP(i, R) {
    Edge p;
    scanf("%d %d %d", &p.from, &p.to, &p.cost);
    G[p.from].push_back(p);
    G[p.to].push_back(p);
  }
  dijkstra();
  return 0;
}
