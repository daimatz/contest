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

int d[300][300];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 300) REP(j, 300) d[i][j] = INF;

  scanf("%d%d", &N, &M);
  REP(i, M) {
    int c;
    scanf("%d", &c);
    vector<int> tmp(c);
    REP(j, c) {
      scanf("%d", &tmp[j]);
      --tmp[j];
    }
    REP(j, c) REP(k, c)
      if (j != k)
        d[tmp[j]][tmp[k]] = 1;
  }

  REP(k, N) REP(i, N) REP(j, N)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int ans = INF;
  REP(i, N) {
    int sum = 0;
    REP(j, N) {
      if (i != j) sum += d[i][j];
    }
    ans = min(ans, 100*sum/(N-1));
  }
  printf("%d\n", ans);

  return 0;
}
