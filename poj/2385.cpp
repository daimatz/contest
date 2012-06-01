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

int T, W;
int pos[1001];
int ans[1001][31];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d", &T, &W);
  REP(i, T) scanf("%d", pos+i);

  ans[0][0] = (pos[0] == 1) ? 1 : 0;
  for (int i = 1; i <= W; i++) ans[0][i] = 1;

  for (int i = 1; i < T; i++) {
    REP(j, W+1) {
      int m = ans[i-1][j];
      if (j % 2 == 0 && pos[i] == 1) ++m;
      if (j % 2 == 1 && pos[i] == 2) ++m;
      REP(k, j+1) {
        int tmp = ans[i-1][k];
        if (k % 2 == 0 && pos[i] == 1) ++tmp;
        else if (k % 2 == 1 && pos[i] == 2) ++tmp;
        if (tmp > m) m = tmp;
      }
      ans[i][j] = m;
    }
  }

  //REP(i, T) { REP(j, W+1) printf("%d ", ans[i][j]); puts(""); }

  int m = ans[T-1][0];
  REP(i, W+1) if (m < ans[T-1][i]) m = ans[T-1][i];
  printf("%d\n", m);

  return 0;
}
