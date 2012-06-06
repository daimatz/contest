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

#define INF (INT_MAX/3)
#define EPS (1.0e-8)

#define MAX_N 16

int t[MAX_N+1][MAX_N+1];
int ans[(1<<MAX_N)-1];
int N;

int solve(int n) {
  if (n == 0) return 0;
  if (ans[n] != -1) return ans[n];
  ans[n] = INF;
  REP(i, N) {
    if ((n | (1<<i)) == n) {
      int m = t[i+1][0];
      int nn = n - (1<<i);
      for (int j = 1; j <= N; ++j)
        if ((nn & (1<<(j-1))) != 0 && t[i+1][j] < m)
          m = t[i+1][j];
      int s = m + solve(nn);
      if (ans[n] > s)
        ans[n] = s;
    }
  }
  return ans[n];
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    scanf("%d", &N);
    if (N == 0) break;
    memset(ans, -1, sizeof(ans));
    //REP(i, 1<<N) ans[i] = INF;
    REP(i, N) REP(j, N+1)
      scanf("%d", &t[i+1][j]);
    //REP(i, N) t[i+1][i+1] = INF;
    //REP(i, N) ans[1<<i] = t[i+1][0];
    printf("%d\n", solve((1<<N)-1));
    //REP(i, 1<<N) DEBUG(ans[i]);
  }

  return 0;
}
