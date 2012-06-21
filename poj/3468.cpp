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

int N, Q;

ll data[(1<<18)-1], datb[(1<<18)-1];

void add(int a, int b, int x, int k, int l, int r) {
  if (a <= l && r <= b) {
    data[k] += x;
  } else if (l < b && a < r) {
    datb[k] += (min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

ll sum(int a, int b, int k, int l, int r) {
  if (b <= l || r <= a) return 0;
  if (a <= l && r <= b) return data[k] * (r-l) + datb[k];
  else {
    ll res = (min(b,r)-max(a,l)) * data[k];
    res += sum(a,b,k*2+1,l,(l+r)/2);
    res += sum(a,b,k*2+2,(l+r)/2,r);
    return (res);
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d", &N, &Q);
  REP(i, N) {
    int tmp;
    scanf("%d", &tmp);
    add(i, i+1, tmp, 0, 0, N);
  }
  REP(i, Q) {
    char c = '\0';
    while (c != 'C' && c != 'Q' && c != EOF) c = getchar();
    if (c == EOF) break;
    if (c == 'Q') {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%lld\n", sum(a-1, b, 0, 0, N));
    } else if (c == 'C') {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      add(a-1, b, c, 0, 0, N);
    }
  }

  return 0;
}
