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

int N, M;

typedef pair<int,int> P;

vector<vector<P> > e;

int prim() {
  bool used[N];
  fill_n(used,N,false);
  priority_queue<P, vector<P>, greater<P> > q;
  q.push(P(0,0));
  int ret = 0;
  int vis = 0;
  while (!q.empty()) {
    P p = q.top(); q.pop();
    int c = p.second, cc = p.first;
    if (used[c]) continue;
    ++vis;
    used[c] = true;
    ret = max(ret, cc);
    if (vis == N) return ret;
    REP(i, e[c].size()) {
      if (!used[e[c][i].first])
        q.push(P(e[c][i].second, e[c][i].first));
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d", &N, &M);
  e.resize(N);
  REP(i, M) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x; --y;
    e[x].push_back(P(y,z));
    e[y].push_back(P(x,z));
  }

  printf("%d\n", prim());

  return 0;
}
