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

short step[2002];

struct P {
  short n, t;
  short s[14];
  P(short _n, short _t, const short _s[]) {
    n = _n; t = _t;
    memcpy(s,_s,sizeof(s));
  }
};

void solve() {
  memset(step, -1, sizeof(step));
  step[1] = 0;
  short s[14];
  memset(s,-1,sizeof(s));
  s[0] = 1;
  queue<P> q;
  q.push(P(1, 0, s));
  set<short> yet;
  for (short i = 1; i <= 1000; i++) yet.insert(i);
  while (!q.empty() && !yet.empty()) {
    P p = q.front(); q.pop();
    if (step[p.n] != -1 && step[p.n] < p.t) continue;
    yet.erase(p.n);
    short nn;
    short *ptr = p.s;
    while (*ptr != -1) ++ptr;
    REP(i, 14) {
      if (p.s[i] == -1) break;
      for (short j = -1; j <= 1; j+=2) {
        nn = p.n + p.s[i] * j;
        if (nn > 0 && nn < 2002 && p.t < 13 && (step[nn] == -1 || p.t+1 <= step[nn])) {
          step[nn] = p.t+1;
          *ptr = nn;
          q.push(P(nn, p.t+1, p.s));
          *ptr = -1;
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    printf("%d\n", step[n]);
  }

  return 0;
}
