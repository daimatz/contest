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

typedef pair<int,int> P;
int N, M;
vector<vector<P> > e(1000);

int prim() {
  bool used[1000];
  fill(used,used+N,false);
  int vis = 0;
  int ret = 0;
  priority_queue<P> q;

  q.push(P(0,0));
  while (!q.empty()) {
    P p = q.top(); q.pop();
    int c = p.second, cc = p.first;
    if (used[c]) continue;
    used[c] = true;
    ++vis; ret += cc;
    if (vis == N) return ret;
    REP(i, e[c].size())
      if (!used[e[c][i].first])
        q.push(P(e[c][i].second, e[c][i].first));
  }
  return -1;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d", &N, &M);
  REP(i, M) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    e[x].push_back(P(y,z));
    e[y].push_back(P(x,z));
  }
  printf("%d\n", prim());

  return 0;
}
