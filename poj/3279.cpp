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

int N, M;
int cnt;
int ans[15][15];

#define flip(x) x=1-x;

void inline push(int x, int y, int maze[15][15], int used[15][15]) {
  flip(used[y][x]);
  flip(maze[y][x]);
  if (0 <= y-1) flip(maze[y-1][x]);
  if (y+1 < N) flip(maze[y+1][x]);
  if (0 <= x-1) flip(maze[y][x-1]);
  if (x+1 < M) flip(maze[y][x+1]);
}

void solve(int k, int maze[15][15]) {
  int used[15][15];
  memset(used, 0, sizeof(used));

  int ss = 0;

  REP(x, M) {
    if ((1<<x) & k) {
      push(M-x-1, 0, maze, used);
      ++ss;
    }
  }

  for (int y = 1; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (maze[y-1][x] == 1) {
        push(x,y,maze, used);
        ++ss;
      }
    }
  }

  REP(x, M) {
    if (maze[N-1][x] != 0) {
      ss = INF;
      break;
    }
  }

  if (ss < cnt) {
    memcpy(ans, used, sizeof(used));
    cnt = ss;
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int maze[15][15];
  while (scanf("%d%d", &N, &M) != EOF) {
    REP(i, N) REP(j, M) scanf("%d", &maze[i][j]);
    //REP(i, N) {REP(j, M) printf("%d ", maze[i][j]); puts(""); } continue;

    cnt = INF;
    REP(i, 1<<M) {
      int tmp[15][15];
      memcpy(tmp, maze, sizeof(tmp));
      solve(i, tmp);
    }

    if (cnt == INF) puts("IMPOSSIBLE");
    else {
      REP(i, N) {
        REP(j, M) {
          printf("%d ", ans[i][j]);
        }
        puts("");
      }
    }
  }

  return 0;
}
