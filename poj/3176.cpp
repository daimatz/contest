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
#define EPS 1.0e-8

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<vector<int> > values;
  int tmp;
  REP(i, N) {
    vector<int> v;
    REP(j, i+1) {
      cin >> tmp;
      v.push_back(tmp);
    }
    values.push_back(v);
  }
  //DEBUG(values[4][4]);

  int dp[N][N];
  REP(i, N) dp[N-1][i] = values[N-1][i];
  //DEBUG(dp[4][4]);
  for (int i = N-2; i >= 0; --i) {
    REP(j, i+1) {
      dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + values[i][j];
    }
  }
  cout << dp[0][0] << endl;

  return 0;
}
