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

int main(int argc, char *argv[]) {
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    if (a == 0 && b == 0 && c == 0 && d == 0)
      break;
    int ans = 360*3;
    ans += ((a-b+40)%40)*9;
    ans += ((c-b+40)%40)*9;
    ans += ((c-d+40)%40)*9;
    cout << ans << endl;
  }
  return 0;
}
