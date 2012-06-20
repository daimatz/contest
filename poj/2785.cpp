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

int n;
int A[4000], B[4000], C[4000], D[4000];
int P[4000*4000], Q[4000*4000];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
  }
  int t = 0;
  REP(i, n) {
    REP(j, n) {
      P[t] = A[i] + B[j];
      Q[t] = - (C[i] + D[j]);
      ++t;
    }
  }
  sort(P, P+t);
  sort(Q, Q+t);

  ll ans = 0;
  REP(i, t) {
    pair<int*, int*> range = equal_range(P, P+t, Q[i]);
    ans += distance(range.first, range.second);
    //ans += upper_bound(P, P+t, Q[i]) - lower_bound(P, P+t, Q[i]);
  }

  printf("%lld\n", ans);

  return 0;
}
