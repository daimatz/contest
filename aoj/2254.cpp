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

#define MAX_N 16

int t[MAX_N+1][MAX_N+1];

int N;

int main(int argc, char *argv[]) {

  while (1) {
    scanf("%d", &N);
    if (N == 0) break;

    REP(i, N) {
      REP(j, N+1) {
        scanf("%d", &t[i+1][j]);
      }
    }

    int ans = INF;
    REP(i, N) {
      int cost = t[i+1][0];
      REP(j, N) {
        if (i == j) continue;
        cost += t[j+1][i+1];
      }
      ans = min(cost, ans);
    }

    cout << ans << endl;
  }
  return 0;
}
