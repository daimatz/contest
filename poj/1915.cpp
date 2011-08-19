/*
 last updated: 2010/06/21 06:44:48
 */
#include <iostream>
#include <queue>
using namespace std;

class vec {
public:
  int x;
  int y;
  int c;
  vec operator=(vec v);
  bool operator==(vec v);
  vec(int x, int y) { this->x = x, this->y = y, this->c = 0; }
  vec();
  void move(int m[2]) { this->x += m[0], this->y += m[1], this->c++; }
};

bool vec::operator==(vec v) {
  return (this->x == v.x && this->y == v.y);
}

vec vec::operator=(vec v) {
  this->x = v.x;
  this->y = v.y;
  this->c = v.c;
  return *this;
}

int main() {
  int n, l, sx,sy, ex,ey;
  cin >> n;
  while (n--) {
    cin >> l;
    int visited[l][l];
    for (int i = 0; i < l; i++)
      for (int j = 0; j < l; j++)
        visited[i][j] = 0;
    int m[8][2] = {{1,2},{2,1},{-1,2},{-2,1},
                   {1,-2},{2,-1},{-1,-2},{-2,-1}};
    cin >> sx >> sy;
    cin >> ex >> ey;
    vec s(sx, sy), e(ex, ey);
    queue<vec> q;
    visited[s.x][s.y] = 1;
    q.push(s);
    while (!q.empty()) {
      s = q.front();
      q.pop();
      if (s == e) {
        cout << s.c << endl;
        break;
      }
      for (int i = 0; i < 8; i++) {
        int x = s.x + m[i][0], y = s.y + m[i][1];
        if (x >= 0 && x < l && y >= 0 && y < l && !visited[x][y]) {
          s.move(m[i]);
          visited[s.x][s.y] = 1;
          q.push(s);
        }
      }
    }
  }
  return 0;
}

/**
 * int main(int argc, char *argv[]) {
 *   int n, l, s[2], e[2];
 *   cin >> n;
 *   while (n--) {
 *     cin >> l;
 *     int visited[l][l];
 *     for (int i = 0; i < l; i++)
 *       for (int j = 0; j < l; j++)
 *         visited[i][j] = 0;
 *     int move[8][2] = {{1,2},{2,1},{-1,2},{-2,1},
 *                       {1,-2},{2,-1},{-1,-2},{-2,-1}};
 *     cin >> s[0] >> s[1];
 *     cin >> e[0] >> e[1];
 *     queue<int> x;
 *     queue<int> y;
 *     queue<int> c;
 *     visited[s[0]][s[1]] = 1;
 *     x.push(s[0]); y.push(s[1]); c.push(0);
 *     while (!x.empty() && !y.empty()) {
 *       int cnt = c.front(); c.pop();
 *       s[0] = x.front(); x.pop();
 *       s[1] = y.front(); y.pop();
 *       if (s[0] == e[0] && s[1] == e[1]) {
 *         cout << cnt << endl;
 *         break;
 *       }
 *       for (int i = 0; i < 8; i++) {
 *         int v[2] = {s[0]+move[i][0], s[1]+move[i][1]};
 *         if (v[0] >= 0 && v[0] < l
 *             && v[1] >= 0 && v[1] < l
 *             && !visited[v[0]][v[1]]) {
 *           visited[v[0]][v[1]] = 1;
 *           x.push(v[0]); y.push(v[1]); c.push(cnt+1);
 *         }
 *       }
 *     }
 *   }
 *   return 0;
 * }
 */
