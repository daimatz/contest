#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_W 50
#define MAX_H 50

int W, H;
int maze[MAX_H][MAX_W];
int cnt;

int dx[] = {1,1,1,0,-1,-1,-1,0}, dy[] = {1,0,-1,-1,-1,0,1,1};

void dfs(int x, int y) {
  //cout << x << " " << y << endl;
  if (maze[y][x] == 1) maze[y][x] = 2;
  else return;
  REP(i, 8) {
    int nx = x + dx[i], ny = y + dy[i];
    if (0 <= nx && nx < W && 0 <= ny && ny < H) {
      dfs(nx, ny);
    }
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0) break;
    cnt = 0;
    REP(i, H) REP(j, W) {
      scanf("%d", &maze[i][j]);
    }
    REP(i, H) REP(j, W) {
      if (maze[i][j] == 1) {
        cnt++;
        dfs(j, i); // not dfs(i, j); :(
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
