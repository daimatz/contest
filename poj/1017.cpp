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

int p[6];

// 1x1 to remaining 2x2 space
void f() {
  if (p[1] < 0) {
    p[0] -= -p[1] * 4;
    p[1] = 0;
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    REP(i, 6) cin >> p[i];
    if (*max_element(p,p+6) == 0) break;
    int ans = 0;
    // 6x6
    ans += p[5];
    // 5x5
    ans += p[4];
    // 1x1 to remaining space
    p[0] -= p[4]*11;
    // 4x4
    ans += p[3];
    // 2x2 to ramaining space
    p[1] -= p[3]*5;
    f();
    // 3x3
    ans += p[2] / 4;
    int k;
    if ((k = p[2] % 4) != 0) {
      ++ans;
      if (k == 1) {
        p[1] -= 5;
        f();
        p[0] -= 7;
      } else if (k == 2) {
        p[1] -= 3;
        f();
        p[0] -= 6;
      } else {
        p[1] -= 1;
        f();
        p[0] -= 5;
      }
    }
    // 2x2
    if (p[1] > 0) {
      ans += p[1] / 9;
      if ((k = p[1] % 9) != 0) {
        ++ans;
        p[0] -= (9-k)*4;
      }
    }
    // 1x1
    if (p[0] > 0) {
      ans += p[0] / 36;
      if (p[0] % 36 != 0) ++ans;
    }
    printf("%d\n", ans);
  }

  return 0;
}
