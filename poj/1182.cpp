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

int N, K;
int T[100000], X[100000], Y[100000];

int par[150000], ran[150000];

void init(int n) {
  REP(i, n) par[i] = i, ran[i] = 0;
}

int find(int x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (ran[x] < ran[y]) par[x] = y;
  else {
    par[y] = x;
    if (ran[x] == ran[y]) ran[x]++;
  }
}

bool same(int x, int y) {
  return (find(x) == find(y));
}

void solve() {
  init(N*3);
  int ans = 0;
  REP(i, K) {
    int x = X[i]-1, y = Y[i]-1;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ++ans;
      continue;
    }

    if (T[i] == 1) {
      if (same(x, y+N) || same(x, y+2*N)) ++ans;
      else {
        unite(x, y);
        unite(x+N, y+N);
        unite(x+2*N, y+2*N);
      }
    } else {
      if (same(x,y) || same(x, y+2*N)) ++ans;
      else {
        unite(x, y+N);
        unite(x+N, y+2*N);
        unite(x+2*N, y);
      }
    }
  }
  printf("%d\n", ans);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d", &N, &K);
  REP(i, K) scanf("%d%d%d", T+i, X+i, Y+i);
  solve();

  return 0;
}
