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
#define EPS (1.0e-6)

typedef complex<double> Point;

int N = 0;
int n, d;
vector<pair<double, Point> > Ps;

namespace std {
  bool operator<(const Point &a, const Point &b) {
    if (abs(a.real()-b.real()) < EPS)
      return a.imag() < b.imag();
    return a.real() < b.real();
  }
};

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y;
  while (1) {
    scanf("%d%d", &n, &d);
    if (n == 0 && d == 0) break;
    Ps.clear();
    REP(i, n) {
      scanf("%d%d", &x, &y);
      Ps.push_back(make_pair(x+sqrt(d*d-y*y), Point(x,y)));
    }

    sort(ALLOF(Ps));
    int ans = 0;

    for (vector<pair<double, Point> >::iterator it = Ps.begin(); it != Ps.end(); ) {
      ++ans;
      double y = (it->second).imag();
      if (abs(y) > d) {
        ans = -1;
        break;
      }
      Point p(it->first, 0);
      while (it != Ps.end() && abs(it->second - p) <= d + EPS) {
        ++it;
      }
    }
    printf("Case %d: %d\n", ++N, ans);
  }

  return 0;
}
