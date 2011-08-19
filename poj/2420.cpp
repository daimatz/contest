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

struct cood {
  int x, y;
  cood(int a, int b) { x=a,y=b;}
};

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
double dd = 5000;

int n;
vector<cood> v;

double d(int gx, int gy) {
  double len = 0;
  REP(i, n) {
    len += sqrt( (gx - v[i].x) * (gx - v[i].x) + (gy - v[i].y) * (gy - v[i].y));
  }
  return len;
}

int main(int argc, char *argv[]) {
  double gx = 0, gy = 0;

  cin >> n;
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    v.push_back(cood(x,y));
    gx += x; gy += y;
  }
  gx /= n; gy /= n;

  double ans = d(gx, gy);

  while (dd > 0.01) {
    double min = ans;

    int min_i = -1;
    REP(i, 4) {
      double len = d(gx+dx[i]*dd, gy+dy[i]*dd);
      if (min > len) {
        min = len;
        min_i = i;
      }
    }
    if (min_i == -1) {
      dd /= 2;
    } else {
      gx += dx[min_i]*dd;
      gy += dy[min_i]*dd;
      ans = min;
    }
  }
  cout << round(ans) << endl;

  return 0;
}
