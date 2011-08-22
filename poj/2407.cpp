#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 1000000000
//int memo[MAX_N+1];

bool relatively_prime(int a, int b) {
  REP(i, max(a, b)) {
    if (i < 2) continue;
    if (a % i == 0 && b % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int ans = 1;
    REP(i, n) {
      if (i < 2) continue;
      if (relatively_prime(i, n))
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
