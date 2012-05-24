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

#define MAX_ML 10000
#define MAX_MD 10000
#define MAX_N 1000

int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N];

void solve() {
  fill(d, d+N, INF);
  d[0] = 0;

  // bellman-ford
  REP(k, N) {
    // i+1 to i, cost 0
    REP(i, N-1) {
      if (d[i+1] < INF) d[i] = min(d[i], d[i+1]);
    }
    // AL to BL, cost DL
    REP(i, ML) {
      if (d[AL[i]-1] < INF)
        d[BL[i]-1] = min(d[BL[i]-1], d[AL[i]-1] + DL[i]);
    }
    // BD to AD, cost -DD
    REP(i, MD) {
      if (d[BD[i]-1] < INF)
        d[AD[i]-1] = min(d[AD[i]-1], d[BD[i]-1] - DD[i]);
    }
  }

  int res = d[N-1];
  if (d[0] < 0) {
    res = -1;
  } else if (res == INF) {
    res = -2;
  }
  cout << res << endl;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d%d", &N, &ML, &MD);
  REP(i, ML) {
    scanf("%d%d%d", AL+i, BL+i, DL+i);
  }
  REP(i, MD) {
    scanf("%d%d%d", AD+i, BD+i, DD+i);
  }

  solve();

  return 0;
}
