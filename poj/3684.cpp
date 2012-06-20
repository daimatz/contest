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
#define EPS (1.0e-8)

const double g = 10.0;
int C, N, H, R, T;
double y[100];

double calc(int T) {
  if (T < 0) return H;
  double t = sqrt(2*H/g);
  int k = (int)(T/t);
  if (k % 2 == 0) {
    double d = T - k * t;
    return H - g * d * d / 2;
  } else {
    double d = k * t + t - T;
    return H - g * d * d / 2;
  }
}

void solve() {
  REP(i, N) {
    y[i] = calc(T-i);
  }
  sort(y, y+N);
  REP(i, N) {
    printf("%.2f ", y[i] + 2*R*i / 100.0);
  }
  puts("");
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d", &C);
  REP(c, C) {
    scanf("%d%d%d%d", &N, &H, &R, &T);
    solve();
  }

  return 0;
}
