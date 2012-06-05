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

typedef complex<double> Point;

int N, D;
Point P[1001];
set<int> neighbor[1001];
bool repaired[1001];

int par[1001];
int ran[1001];

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
  return find(x) == find(y);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> D;
  REP(i, N) {
    int x, y;
    cin >> x >> y;
    P[i] = Point(x,y);
    repaired[i] = false;
  }
  REP(i, N) REP(j, i) {
    if (i != j && abs(P[i] - P[j]) <= D + EPS) {
      neighbor[i].insert(j);
      neighbor[j].insert(i);
    }
  }

  init(N);

  char c;
  while (cin >> c) {
    if (c == 'O') {
      int o;
      cin >> o;
      --o;
      repaired[o] = true;
      FOR(it, neighbor[o]) {
        if (repaired[*it]) unite(o, *it);
      }
    } else if (c == 'S') {
      int s, t;
      cin >> s >> t;
      --s; --t;
      cout << (same(s,t) ? "SUCCESS" : "FAIL") << endl;
    } else {
      puts("Input must start with 'O' or 'S'.");
    }
  }

  return 0;
}
