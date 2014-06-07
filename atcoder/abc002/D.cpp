#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 12;

int N, M;
bool in[MAX_N][MAX_N];

int count_bit(int x) {
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    if (x & (1 << i)) ++ret;
  }
  return ret;
}

void solve() {
  int ans = 0;
  for (int bit = 0; bit < (1 << N); ++bit) {
    if (count_bit(bit) == 0) continue;
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      if (! (bit & (1 << i))) continue;
      for (int j = 0; j < N; ++j) {
        if (! (bit & (1 << j))) continue;
        if (!in[i][j] && !in[j][i]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) ans = max(ans, count_bit(bit));
  }
  cout << ans << endl;
}

int main() {
  cin >> N >> M;
  int x, y;
  for (int i = 0; i < N; ++i) {
    in[i][i] = true;
  }
  for (int i = 0; i < M; ++i) {
    cin >> x >> y;
    --x; --y;
    in[x][y] = true;
  }
  solve();
}
