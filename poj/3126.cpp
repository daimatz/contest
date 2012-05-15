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
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

bool npr[10000];
int x, y;

typedef pair<int, int> P;

void solve() {
  queue<P> q;
  q.push(P(x, 0));
  set<P> visited;
  while (!q.empty()) {
    P p = q.front(); q.pop();
    if (visited.count(p) > 0) continue;
    visited.insert(p);
    if (p.first == y) {
      cout << p.second << endl;
      return;
    }
    REP(i, 4) {
      char s[5];
      sprintf(s, "%d", p.first);
      REP(j, 10) {
        s[i] = '0' + j;
        int v = atoi(s);
        if (!npr[v])
          q.push(P(v, p.second+1));
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  npr[0] = npr[1] = true;
  for (int i = 2; i < 10000; i++) {
    if (!npr[i])
      for (int j = i*2; j < 10000; j+=i)
        npr[j] = true;
  }
  REP(i, 1000)
    npr[i] = true;

  int n;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    solve();
  }

  return 0;
}
