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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

int n, m;

int main(int argc, char *argv[]) {
  scanf("%d %d", &n, &m);
  int score[n][m];
  bool highest[n];

  REP(i, n) {
    highest[i] = false;
    string in;
    cin >> in;
    REP(j, m) {
      score[i][j] = (int)((char)(in[j]) - '0');
    }
  }

  //REP(i, n) REP(j, m) cout << score[i][j] << endl;
  REP(j, m) {
    int h = 0;
    REP(i, n) {
      if (score[i][j] > h) h = score[i][j];
    }
    REP(i, n) {
      if (score[i][j] == h) highest[i] = true;
    }
  }

  int ans = 0;
  REP(i, n) {
    if (highest[i]) ans++;
  }

  cout << ans << endl;

  return 0;
}
