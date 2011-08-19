/*
 last updated: 2010/06/21 07:57:25
 */
#include <iostream>
using namespace std;

char b(char b1, char b2) {
  switch (b1) {
  case 'R':
    if (b2 == 'P') return 'P';
    return 'R';
  case 'S':
    if (b2 == 'R') return 'R';
    return 'S';
  case 'P':
    if (b2 == 'S') return 'S';
    return 'P';
  default:
    return b2;
  }
}

char w(char c) {
  if (c == 'R') return 'P';
  else if (c == 'S') return 'R';
  else if (c == 'P') return 'S';
  else return 'M';
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int r, c, n;
    cin >> r >> c >> n;
//    n = 1;
    char v[r+2][c+2];
    for (int i = 0; i < r + 2; i++)
      for (int j = 0; j < c + 2; j++)
        if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
          v[i][j] = 'N';
        else
          cin >> v[i][j];
    while (n--) {
      int up[r+2][c+2];
      for (int i = 1; i < r + 1; i++)
        for (int j = 1; j < c + 1; j++) {
          char win = w(v[i][j]);
          if (v[i][j+1] == win || v[i][j-1] == win
              || v[i+1][j] == win || v[i-1][j] == win)
            up[i][j] = win;
          else
            up[i][j] = v[i][j];
        }
    for (int i = 0; i < r + 2; i++)
      for (int j = 0; j < c + 2; j++)
        if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
          v[i][j] = 'N';
        else
          v[i][j] = up[i][j];
    }
    for (int i = 1; i < r + 1; i++) {
      for (int j = 1; j < c + 1; j++) {
        cout << v[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
