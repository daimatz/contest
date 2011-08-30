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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 50000

int T, N;
vector<int> x, y;

int main(int argc, char *argv[]) {
  //cin >> T >> N;
  scanf("%d %d", &T, &N);
  REP(i, N) {
    int tmp;
    //cin >> tmp;
    scanf("%d", &tmp);
    if (tmp >= 0) x.push_back(tmp);
    else y.push_back(tmp);
  }
  sort(ALLOF(x));
  sort(ALLOF(y), greater<int>());
  x.push_back(INF);
  y.push_back(-INF);

  int xi, yi, ans;
  xi = yi = ans = 0;

  int prev = 0;
  while (1) {
    if (x[xi] < -y[yi]) {
      T -= abs(x[xi] - prev);
      prev = x[xi];
      xi++;
    } else {
      T -= abs(y[yi] - prev);
      prev = y[yi];
      yi++;
    }
    if (T < 0) break;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
