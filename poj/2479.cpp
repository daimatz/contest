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

const int MAX_N = 100000;

int N;
int A[MAX_N];
ll S[MAX_N][5];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", A+i);
    REP(i, N) S[i][0] = S[i][1] = S[i][2] = S[i][3] = S[i][4] = -INF;

    REP(i, N) {

      S[i][0] = 0;

      if (i == 0) S[i][1] = A[0];
      else S[i][1] = max(S[i-1][1] + A[i], S[i-1][0] + A[i]);

      if (i == 0) S[i][2] = A[0];
      else S[i][2] = max(S[i-1][2], S[i][1]);

      if (i == 0) S[i][3] = -INF;
      else if (i == 1) S[i][3] = A[0] + A[1];
      else S[i][3] = max(S[i-1][3] + A[i], S[i-1][2] + A[i]);

      if (i == 0) S[i][4] = -INF;
      else if (i == 1) S[i][4] = A[0] + A[1];
      else S[i][4] = max(S[i-1][4], S[i][3]);

    }
    printf("%lld\n", S[N-1][4]);
    /**
     * REP(i, N) {
     *   REP(j, 5) DEBUG(S[i][j]);
     *   DEBUG("-----");
     * }
     */
  }

  return 0;
}
