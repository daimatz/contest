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
#define EPS (1.0e-10)

char c[500][500];
int sx, sy, ex, ey;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int N, M;
double ans;
double t[500*500+1];

double getNum(double target, double limit) {
  int l = 0, r = 500*500;
  while (1) {
    if (abs(l-r) < 2) break;
    int mid = (l+r)/2;
    if (t[mid]*target >= limit) l = mid;
    else r = mid-1;
  }
  if (l>r) swap(l,r);
  if (t[r] * target >= limit) return r;
  if (t[l] * target >= limit) return l;
  return -1;
}

int limitTime[500][500];
void setLimit(double lim) {
  REP(i, N) REP(j, M) {
    if (isalpha(c[i][j])) limitTime[i][j] = INF;
    else if (c[i][j] == '#') limitTime[i][j] = -1;
    else limitTime[i][j] = getNum(c[i][j] - '0', lim);
  }
}

double cost[500][500];
bool canReach() {
  REP(i, 500) REP(j, 500) cost[i][j] = INF;
  cost[sy][sx] = 0;
  queue<pair<int,int> > q;
  q.push({sy,sx});
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    if (p == make_pair(ey,ex)) return true;
    int nextCost = cost[p.first][p.second] + 1;
    REP(i, 4) {
      int nx = p.second + dx[i], ny = p.first + dy[i];
      if (0 <= nx && nx < M && 0 <= ny && ny < N && c[ny][nx] != '#' && cost[ny][nx] == INF && nextCost <= limitTime[ny][nx]) {
        cost[ny][nx] = nextCost;
        q.push({ny,nx});
      }
    }
  }
  return false;
}

void solve() {
  double l = 0, r = 9;
  setLimit(0);
  if (!canReach()) {
    ans = -1;
    return;
  }
  while (abs(l-r) > EPS) {
    double mid = (l+r) / 2;
    setLimit(mid);
    if (canReach()) l = mid;
    else r = mid;
  }
  ans = (l+r)/2;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  t[0] = 1;
  for (int i = 1; i < 500*500+1; i++) t[i] = t[i-1] * 0.99;

  scanf("%d%d\n", &N, &M);
  REP(i, N) {
    REP(j, M) {
      c[i][j] = getchar();
      if (c[i][j] == 's') sx = j, sy = i;
      if (c[i][j] == 'g') ex = j, ey = i;
    }
    getchar();
  }
  solve();
  printf("%.9f\n", ans);

  return 0;
}
