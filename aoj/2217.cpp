#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

const int MAX_N = 100;
int N;
bool flag[MAX_N][MAX_N];
pair<int, int> map[MAX_N][MAX_N];
int sx, sy;
int cnt = 0;

bool dfs(int x, int y) {
  if (x == sx && y == sy) {
    cnt++;
    return true;
  }
  if (flag[x][y]) {
    return false;
  }
  flag[x][y] = true;
  if (dfs(map[x][y].first, map[x][y].second)) {
    return true;
  }
  flag[x][y] = false;
  return false;
}

int main(int argc, char *argv[]) {
  while (true) {
    // input
    scanf("%d", &N);
    if (N == 0)
      break;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        int nx, ny;
        scanf("%d %d", &nx, &ny);
        map[x][y] = pair<int, int>(nx, ny);
        flag[x][y] = false;
      }
    }

    cnt = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (flag[x][y] == false) {
          // dfs
          sx = x, sy = y;
          //DEBUG(sx); DEBUG(sy);
          flag[x][y] = true;
          dfs(map[x][y].first, map[x][y].second);
        }
      }
    }

    cout << cnt << endl;
  }
  return 0;
}
