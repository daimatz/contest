#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 100000
#define MAX_S 100000000
int n, S, a[MAX_N], T;

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &S);
    REP(i, n) {
      scanf("%d", a+i);
    }
    int s = 0, t = 0, sum = 0;
    int res = INF;
    while (1) {
      while (t < n && sum < S)
        sum += a[t++];
      if (sum < S)
        break;
      res = min(res, t-s);
      sum -= a[s++];
    }
    if (res > n)
      res = 0;
    cout << res << endl;
  }
  return 0;
}
