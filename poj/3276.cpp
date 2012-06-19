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

int N;
int D[5000];
int flag[5000];

int f(int k) {
  memset(flag, 0, sizeof(flag));
  int ret = 0, sum = 0;
  REP(i, N-k+1) {
    if ((D[i] + sum) % 2 != 0) {
      ++ret;
      flag[i] = 1;
    }
    sum += flag[i];
    if (i - k + 1 >= 0) sum -= flag[i-k+1];
  }
  for (int i = N-k+1; i < N; ++i) {
    if ((D[i] + sum) % 2 != 0) return INF;
    if (i-k+1 >= 0) sum -= flag[i-k+1];
  }
  return ret;
}

void solve() {
  int mk = INF, mm = INF;
  for (int k = 1; k <= N; k++) {
    int tmp = f(k);
    if (tmp < mm) {
      mm = tmp;
      mk = k;
    }
  }
  printf("%d %d\n", mk, mm);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d\n", &N);
  char c;
  REP(i, N) {
    scanf("%c\n", &c);
    D[i] = (c == 'B' ? 1 : 0);
  }

  solve();

  return 0;
}
