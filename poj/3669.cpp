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

#define N 310

int maze[N][N];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
bool visited[N][N];

struct P {
  int x, y, t;
  P(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

bool safe(int x, int y, int t) {
  if (maze[x][y] <= t) return false;
  if (x > 0 && maze[x-1][y] <= t) return false;
  if (x < N-1 && maze[x+1][y] <= t) return false;
  if (y > 0 && maze[x][y-1] <= t) return false;
  if (y < N-1 && maze[x][y+1] <= t) return false;
  return true;
}

bool safe(int x, int y) {
  return safe(x,y,INF-1);
}

void solve() {
  memset(visited, 0, sizeof(visited));
  queue<P> q;
  for (q.push(P(0,0,0)); !q.empty(); q.pop()) {
    P p = q.front();
    if (visited[p.x][p.y]) continue;
    visited[p.x][p.y] = true;
    if (safe(p.x, p.y)) {
      printf("%d\n", p.t);
      return;
    }
    REP(i, 4) {
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < N && safe(nx,ny,p.t+1)) {
        q.push(P(nx,ny,p.t+1));
      }
    }
  }
  puts("-1");
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, N) REP(j, N) maze[i][j] = INF;

  int M;
  scanf("%d", &M);
  REP(i, M) {
    int x, y, t;
    scanf("%d%d%d", &x,&y,&t);
    maze[x][y] = t;
  }
  solve();

  return 0;
}
