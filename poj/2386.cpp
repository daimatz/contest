/**
 * -*- coding: utf-8-unix -*-
 * last updated: 2010/11/22 02:42:35
 */

#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int n, m;

void dfs(int x, int y, string map[]) {
  if (map[x][y] != 'W')
    return;
  map[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x+dx, ny = y+dy;
      if (0 <= nx && nx < n && 0 <= ny && ny < m)
        dfs(nx, ny, map);
    }
}

void solve(string map[]) {
  int c = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (map[i][j] == 'W') {
        c++;
        dfs(i, j, map);
      }
  cout << c << endl;
}

int main(int argc, char *argv[]) {
  while (cin >> n >> m) {
    string map[n];
    for (int i = 0; i < n; i++)
      cin >> map[i];
    solve(map);
  }
  return 0;
}
