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

#define MAX_N 1000000000
#define MAX_M 1000000000
#define MAX_K 10000

typedef long long ll;

struct P {
  int x, y;
  P() { x=y=0; }
  P(int _x, int _y) { x = _x, y = _y; }
  P operator+(P p) { return P(x+p.x, y+p.y); }
  P operator-(P p) { return P(x-p.x, y-p.y); }
  int operator/(P p) { return min(x/p.x, y/p.y); }
  void print() { cout << x << " " << y << endl; }
};

int n, m;
int sx, sy;
int k;
P v[MAX_K];

bool valid(P p) {
  return (1 <= p.x && p.x <= n && 1 <= p.y && p.y <= m);
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  cin >> sx >> sy;
  cin >> k;

  REP(i, k) {
    int x, y;
    cin >> x >> y;
    v[i] = P(x, y);
  }

  P pos(sx, sy), reg(n, m);
  ll ans = 0;
  REP(i, k) {
    ans += (reg-pos)/v[i];
  }

  cout << ans << endl;

  return 0;
}
