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
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 100

int n, m;
int s[MAX_N], t[MAX_N];
int ss, tt;

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
      break;
    ss = tt = 0;
    REP(i, n) {
      scanf("%d", s+i);
      ss += s[i];
    }
    REP(i, m) {
      scanf("%d", t+i);
      tt += t[i];
    }

    int as = INF, at = INF;
    REP(i, n) {
      int to_t = s[i];
      REP(j, m) {
        int to_s = t[j];
        if (ss - to_t + to_s == tt - to_s + to_t &&
            as + at > to_t + to_s) {
          as = to_t, at = to_s;
        }
      }
    }

    if (as == INF && at == INF) printf("-1\n");
    else printf("%d %d\n", as, at);
  }
  return 0;
}
