#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

const int MAX_N = 100;

int T, N;
char R[MAX_N];
int B[MAX_N];

int getnext(char c, int start) {
  for (int i = start; i < N; i++)
    if (R[i] == c)
      return B[i];
  return 0;
}

int sign(int n) {
  if (n > 0) return 1;
  if (n < 0) return -1;
  return 0;
}

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  for (int x = 1; x <= T; x++) {
    memset(R,0,MAX_N); memset(B,0,MAX_N);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf(" %c %d", &R[i], &B[i]);
    }

    int oc, bc, on, bn;
    oc = bc = 1;
    on = getnext('O', 0);
    bn = getnext('B', 0);

    int ans = 0, i = 0;
    //DEBUG(oc); DEBUG(bc); DEBUG(on); DEBUG(bn); return 0;

    while (1) { // step by 1 sec.
      //DEBUG(oc); DEBUG(bc);
      //cout << oc << "   " << bc << endl;
      if (i == N)
        break;
      if (oc == on && R[i] == 'O') { // O pushes button
        i++;
        ans++;
        if (bn) bc += sign(bn-bc);
        on = getnext('O', i); // o next
      } else if (bc == bn && R[i] == 'B') { // B pushes button
        i++;
        ans++;
        if (on) oc += sign(on-oc);
        bn = getnext('B', i); // b next
      } else {
        ans++;
        if (on) oc += sign(on-oc);
        if (bn) bc += sign(bn-bc);
      }
    }
    cout << "Case #" << x << ": " << ans << endl;
    //break;
  }
  return 0;
}
