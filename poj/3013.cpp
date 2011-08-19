#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

#define INF (1<<40);

#define MAX_V 50000
#define MAX_E 50000

int T;

struct Edge {
  int to, cost;
  Edge(int t, int c) {
    to = t; cost = c;
  }
  bool operator<(const Edge &a) const {

  }
};

vector<Edge> node[MAX_V+1];

int main(int argc, char *argv[]) {
  int v, e;

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &v, &e);
    int w[v];
    for (int i = 0; i < v; i++) {
      scanf("%d", &w[i]);
    }
    for (int i = 0; i < e; i++) {
      int n1, n2, c;
      scanf("%d %d %d", &n1, &n2, &c);
      Edge tmp1(n1,c), tmp2(n2,c);
      node[n2].push_back(tmp1);
      node[n1].push_back(tmp2);
    }
  }

  return 0;
}
