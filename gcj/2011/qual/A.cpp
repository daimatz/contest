#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

const int MAX_N = 100;
const int MAX_P = 100;

int T, N;
char R[MAX_N];
int B[MAX_N];

int bp, op;

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  for (int x = 1; x <= T; x++) {
    bp = op = 1; // initial place
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
      scanf(" %c %d", &R[i], &B[i]);

    int ans = 0, pans = 0;
    char turn = R[0];
    int tc = 0; // turn count
    for (int i = 0; i < N; i++) {
      if (R[i] == 'O') {
        if (turn == 'B') {
          ans += max(abs(B[i] - op) - tc, 0)+1;
          tc = abs(B[i] - op)+1;
          //tc = ans - pans;
          turn = 'O';
        } else {
          ans += abs(B[i] - op)+1;
          tc += abs(B[i] - op)+1;
          //tc += ans - pans;
        }
        op = B[i];
      } else { // if (R[i] == 'B')
        if (turn == 'O') {
          ans += max(abs(B[i] - bp) - tc, 0)+1;
          tc = abs(B[i] - bp)+1;
          //tc = ans - pans;
          turn = 'B';
        } else {
          ans += abs(B[i] - bp)+1;
          tc += abs(B[i] - bp)+1;
          //tc += ans - pans;
        }
        bp = B[i];
      }
      pans = ans;
      //DEBUG(ans); DEBUG(tc);
    }
    cout << "Case #" << x << ": " << ans << endl;
  }
  return 0;
}
