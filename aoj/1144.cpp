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

#define MAX_W 20
#define MAX_H 20

int m[MAX_W][MAX_H];
int W, H;
int cnt = INF;
int xs[] = {1,0,-1,0}, ys[] = {0,1,0,-1};

void dfs(int sx, int sy, int c) {
  //DEBUG(sx); DEBUG(sy); DEBUG(c);
  if (c > 10)
    return;

  REP(i, 4) {
    int x = sx+xs[i], y = sy+ys[i];
    if ( !(0 <= x && x < W && 0 <= y && y < H))
      continue;
    if (m[x][y] == 1)
      continue;
    while (1) {
      if ( !(0 <= x && x < W && 0 <= y && y < H))
        break;
      if (m[x][y] == 1) {
        //DEBUG(1);
        m[x][y] = 0;
        dfs(x-xs[i], y-ys[i], c+1);
        m[x][y] = 1;
        break;
      }
      if (m[x][y] == 3) {
        cnt = min(c+1, cnt);
        //DEBUG(cnt);
        return;
      }
      x += xs[i]; y += ys[i];
    }
  }
}

int main() {
  while (1) {
    cnt = INF;
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0)
      break;

    int sx, sy;

    REP(y, H) {
      REP(x, W) {
        scanf("%d", &m[x][y]);
        if (m[x][y] == 2) {
          sx = x; sy = y;
          m[x][y] = 0;
        }
      }
    }

    dfs(sx, sy, 0);

    cout << (cnt > 10 ? -1 : cnt) << endl;

  }
}
