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

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  scanf("%d", &N);
  while (N--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int jobs[n];
    REP(i, n) {
      scanf("%d", jobs+i);
    }

    int ans = 0;
    int *s = jobs, *t;
    while (1) {
      ans++;
      t = max_element(jobs, s);
      s = max_element(s, jobs+n);
      if (*t > *s) s = t;
      if (s == jobs+m) break;
      *s = 0;
    }
    printf("%d\n", ans);
  }

  return 0;
}
