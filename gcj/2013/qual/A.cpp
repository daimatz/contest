#include <iostream>

using namespace std;

string board[4];

enum STATE {
  NOT_END,
  X_WON,
  O_WON,
  DRAW
};

STATE check(char a, char b, char c) {
  if (a == b && b == c) {
    if (a == 'X') return X_WON;
    else return O_WON;
  }
}

STATE check(char a, char b, char c, char d) {
  //cout << a << b << c << d <<endl;
  if (a == '.' || b == '.' || c == '.' || d == '.')
    return NOT_END;
  if (a == 'T') return check(b,c,d);
  if (b == 'T') return check(a,c,d);
  if (c == 'T') return check(a,b,d);
  if (d == 'T') return check(a,b,c);
  if (a == b && b == c && c == d) {
    if (a == 'X') return X_WON;
    else return O_WON;
  }
  return DRAW;
}

STATE solve() {
  bool not_end = false;
  STATE s;
  for (int i = 0; i < 4; ++i) {
    s = check(board[i][0], board[i][1], board[i][2], board[i][3]);
    if (s == X_WON || s == O_WON) return s;
    if (s == NOT_END) not_end = true;
  }
  for (int i = 0; i < 4; ++i) {
    s = check(board[0][i], board[1][i], board[2][i], board[3][i]);
    if (s == X_WON || s == O_WON) return s;
    if (s == NOT_END) not_end = true;
  }
  s = check(board[0][0],board[1][1],board[2][2],board[3][3]);
  if (s == X_WON || s == O_WON) return s;
  s = check(board[3][0],board[2][1],board[1][2],board[0][3]);
  if (s == X_WON || s == O_WON) return s;

  return not_end ? NOT_END : DRAW;
}

int T;
int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> board[j];
    }
    string result;
    switch (solve()) {
      case X_WON: result = "X won"; break;
      case O_WON: result = "O won"; break;
      case DRAW:  result = "Draw"; break;
      case NOT_END: result = "Game has not completed"; break;
    }
    printf("Case #%d: %s\n", i, result.c_str());
  }
}
