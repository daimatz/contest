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

#define MAX_N 10

struct pos {
  int x,y,z,cnt;
  pos(int a, int b, int c, int d) {
    x=a,y=b,z=c,cnt=d;
  }
};

int maze[MAX_N][MAX_N][MAX_N];
int N;
int sx,sy,sz,gx,gy,gz;
int route;
int dx[] = {1,0,0,-1,0,0}, dy[] = {0,1,0,0,-1,0}, dz[] = {0,0,1,0,0,-1};

void bfs() {
  route = -1;
  queue<pos> q;
  q.push(pos(sx,sy,sz,0));

  while (!q.empty()) {
    pos p = q.front(); q.pop();
    if (p.x == gx && p.y == gy && p.z == gz) {
      route = p.cnt; return;
    }
    REP(i, 6) {
      int nx=p.x+dx[i], ny=p.y+dy[i], nz=p.z+dz[i];
      if (!(0 <= nx && nx < N && 0 <= ny && ny < N && 0 <= nz && nz < N))
        continue;
      if (maze[nx][ny][nz] == -1 ||
          (maze[nx][ny][nz] >= 0 && maze[nx][ny][nz] > p.cnt+1) ) {
        maze[nx][ny][nz] = p.cnt+1;
        q.push(pos(nx,ny,nz,p.cnt+1));
      }
    }
  }
}

int main(int argc, char *argv[]) {
  string dummy;
  while (1) {
    if (!(cin >> dummy))
      break;
    cin >> N;
    //DEBUG(N);
    REP(i, N) {
      REP(j, N) {
        REP(k, N) {
          char tmp;
          scanf(" %c", &tmp);
          maze[k][j][i] = (tmp == 'X' ? -2 : -1);
        }
      }
    }
    cin >> sx >> sy >> sz;
    cin >> gx >> gy >> gz;
    cin >> dummy;

    /**
     * REP(i, N) {
     *   REP(j, N) {
     *     REP(k, N) {
     *       cout << maze[k][j][i];
     *     }
     *   }
     * }
     */

    bfs();

    if (route == -1)
      cout << "NO ROUTE" << endl;
    else
      cout << N << " " << route << endl;
  }
  return 0;
}
