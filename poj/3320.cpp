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

int P;
int V[1000000];

void solve() {
  set<int> all;
  REP(i, P) all.insert(V[i]);
  int n = all.size();

  int s = 0, t = 0, num = 0;
  map<int, int> count;
  int res = P;
  while (1) {
    while (t < P && num < n)
      if (count[V[t++]]++ == 0)
        ++num;
    if (num < n) break;
    res = min(res, t-s);
    if (--count[V[s++]] == 0)
      --num;
  }
  printf("%d\n", res);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d", &P);
  REP(i, P) scanf("%d", V+i);

  solve();

  return 0;
}
