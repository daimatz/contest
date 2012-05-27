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

int maze[20][20];
int w, h;
int sx, sy;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int ans;

void solve(int x, int y, int step) {
  //cerr<<"x: "<<x<<", y: "<<y<<endl;
  if (step > 10) return;
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (0 <= nx && nx < w && 0 <= ny && ny < h && maze[ny][nx] != 1) {
      while (1) {
        if (!(0 <= nx && nx < w && 0 <= ny && ny < h)) break;
        if (maze[ny][nx] == 1) {
          //cerr<<"1, x: "<<x<<", y: "<<y<<endl;
          maze[ny][nx] = 0;
          solve(nx-dx[i], ny-dy[i], step+1);
          maze[ny][nx] = 1;
          break;
        }
        if (maze[ny][nx] == 3) {
          if (ans > step && step < 10) ans = step+1;
          break;
        }
        nx += dx[i]; ny += dy[i];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    scanf("%d%d", &w, &h);
    if (w == 0 && h == 0) break;
    ans = INF;
    REP(i, h) {
      REP(j, w) {
        scanf("%d", &maze[i][j]);
        if (maze[i][j] == 2) {
          sx = j; sy = i;
          maze[i][j] = 0;
        }
      }
    }
    solve(sx, sy, 0);
    if (ans == INF) puts("-1");
    else printf("%d\n", ans);
  }

  return 0;
}
