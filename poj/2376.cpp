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

int P[1000001];
int N, T;

void solve() {
  int s = 1, e = -1;
  if (P[s] == -1) {
    puts("-1");
    return;
  }
  int ans = 0;
  while (1) {
    ++ans;
    e = P[s];
    if (e >= T) break;
    int ns = s;
    for (int i = e+1; i > s; i--)
      if (P[i] > P[ns]) ns = i;
    if (ns == s) {
      puts("-1");
      return;
    }
    s = ns;
  }
  printf("%d\n", ans);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(P, -1, sizeof(P));

  scanf("%d%d", &N, &T);
  int s, e;
  REP(i, N) {
    scanf("%d%d", &s, &e);
    if (P[s] < e) P[s] = e;
  }
  solve();

  return 0;
}
