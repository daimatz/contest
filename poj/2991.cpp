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

int N, C;
int L[10000];
int S[10000], A[10000];

struct SegmentTree {
  vector<double> vx, vy;
  vector<double> angle;
  SegmentTree() {
    int n = (1<<15)-1;
    vx.resize(n); vy.resize(n);
    angle.resize(n);
  }
  // k: 接点の番号、 l, r: その接点が [l, r)
  void init(int k, int l, int r) {
    angle[k] = vx[k] = 0.0;
    if (r - l == 1) {
      // leaf
      vy[k] = L[l];
    } else {
      // not leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l+r)/2);
      init(chr, (l+r)/2, r);
      vy[k] = vy[chl] + vy[chr];
    }
  }
  // 場所 s の角度が a だけ変更
  // v: 接点の番号、 l, r: その接点が [l, r)
  void change(int s, double a, int v, int l, int r) {
    if (l < s && s < r) {
      int chl = v * 2 + 1, chr = v * 2 + 2;
      int m = (l+r)/2;
      change(s, a, chl, l, m);
      change(s, a, chr, m, r);
      if (s <= m) angle[v] += a;

      double s = sin(angle[v]), c = cos(angle[v]);
      vx[v] = vx[chl] + (c*vx[chr] - s*vy[chr]);
      vy[v] = vy[chl] + (s*vx[chr] + c*vy[chr]);
    }
  }
};

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  const double pi = 2 * acos(0.0);

  while (scanf("%d%d", &N, &C) != EOF) {
    REP(i, N) scanf("%d", L+i);
    REP(i, C) scanf("%d%d", S+i, A+i);

    double prv[10000];

    SegmentTree T;
    T.init(0,0,N);
    for (int i = 1; i < N; ++i) prv[i] = pi;

    REP(i, C) {
      int s = S[i];
      double a = (A[i] / 360.0) * 2 * pi;
      T.change(s, a-prv[s], 0, 0, N);
      prv[s] = a;
      printf("%.2f %.2f\n", T.vx[0], T.vy[0]);
    }
    puts("");
  }

  return 0;
}
