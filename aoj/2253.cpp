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

#define MAX_N 300
#define MAX_X 30
#define MAX_Y 30

int t, n, sx, sy;
//int maze[2*MAX_X+1][2*MAX_Y+1];
int maze[200][200];
int cnt = 0;
int dx[] = {-1,0,1}, dy[] = {-1,0,1};

struct st {
  int x, y, t;
  st(int a, int b, int c) {
    x=a,y=b,t=c;
  }
};

void dfs(int x, int y, int turn) {
  if (maze[x][y] == 2)
    return;
  if (maze[x][y] == 0) {
    cnt++;
    maze[x][y] = 2;
  }
  if (maze[x][y] == 1 || turn == 0)
    return;
  maze[x][y] = 2;
  dfs(x+1,y+1,turn-1);
  dfs(x+1,y,turn-1);
  dfs(x,y-1,turn-1);
  dfs(x-1,y-1,turn-1);
  dfs(x-1,y,turn-1);
  dfs(x,y+1,turn-1);
}

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &t, &n);
    if (t == 0 && n == 0)
      break;
    memset(maze, 0, sizeof(maze));
    REP(i, n) {
      int x, y;
      scanf("%d %d", &x, &y);
      //maze[MAX_X+x][MAX_Y+y] = 1;
      maze[100+x][100+y] = 1;
    }
    scanf("%d %d", &sx, &sy);
    //sx += MAX_X; sy += MAX_Y;
    sx+=100, sy+=100;

    //DEBUG(sx); DEBUG(sy); return 0;

    queue<st> q;

    cnt = 0;
    /**
     * dfs(sx, sy, t);
     * cout << cnt << endl;
     * continue;
     */

    q.push(st(sx, sy, t));
    maze[sx][sy] = 2;
    cnt++;

    while (!q.empty()) {
      st p = q.front(); q.pop();
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if ((dx[i] == 0 && dy[j] == 0)
              || (dx[i] == -dy[j]))
            continue;
          st np(p.x+dx[i],p.y+dy[j],p.t-1);
          //if (0<= np.x && np.x < 2*MAX_X+1 && 0 <= np.y && np.y < 2*MAX_Y+1 &&
          if (maze[np.x][np.y] == 0) {
            cnt++;
            maze[np.x][np.y] = 2;
            if (np.t > 0)
              q.push(np);
          }
        }
      }
    }

    /**
     * REP(i, 2*MAX_X+1) {
     *   REP(j, 2*MAX_Y+1) {
     *     if (maze[i][j] == 2)
     *       cnt++;
     *   }
     * }
     */

    cout << cnt << endl;
//    if (cnt > 6)
//      break;
  }
  return 0;
}
