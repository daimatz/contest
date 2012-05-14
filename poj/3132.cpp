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
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

#define MAX_N 1120
#define MAX_K 14

bool npr[MAX_N+1];
int dp[MAX_K+1][MAX_N+1];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  npr[0] = npr[1] = true;
  REP(i, MAX_N+1) {
    if (!npr[i])
      for (int j = i*2; j < MAX_N+1; j+=i)
        npr[j] = true;
  }

  dp[0][0] = 1;
  REP(i, MAX_N+1) {
    if (!npr[i]) {
      for (int j = MAX_K; j > 0; j--)
        for (int k = i; k < MAX_N+1; k++)
          dp[j][k] += dp[j-1][k-i];
    }
  }

  int n, k;
  while (1) {
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    cout << dp[k][n] << endl;
  }

  return 0;
}
