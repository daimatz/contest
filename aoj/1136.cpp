#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

typedef complex<int> P;

int normalize(P z[], int p) {
  P o = z[0];
  P k = (abs(z[1]-z[0]) == 0) ? P(1,0) : conj(z[1]-z[0]) / abs(z[1]-z[0]);
  //P k = conj(z[1]-z[0]) / abs(z[1]-z[0]);

  for (int i = 0; i < p; i++) {
    z[i] -= o;
    z[i] = k * z[i];
  }

}

int kaiten(P z[], int p) {
  for (int i = 0; i < p; i++) {
    z[i] *= P(0,1);
  }
}

bool eq(P z1[], P z2[], int num) {
  for (int i = 0; i < num; i++) {
    if (! (z1[i].imag() == z2[i].imag() && z1[i].real() == z2[i].real()))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {

  while (1) {

    int n;
    scanf("%d", &n);
    if (n == 0)
      break;

    int num; // chouten no kazu
    scanf("%d", &num);

    P q[num];
    for (int k = 0; k < num; k++) {
      int x, y;
      scanf("%d %d", &x, &y);
      P t(x, y);
      q[k] = t;
    }
    normalize(q, num);

    for (int i = 1; i <= n; i++) {

      int tmp;
      scanf("%d", &tmp);
      if (tmp != num) { // chouten no kazu ga chigau
        for (int k = 0; k < tmp; k++) {
          int x, y;
          scanf("%d %d", &x ,&y);
        }
        continue;
      }

      P p1[num], p2[num];
      for (int k = 0; k < num; k++) {
        int x, y;
        scanf("%d %d", &x, &y);
        P t(x, y);
        p1[k] = p2[num-k-1] = t;
      }
      normalize(p1, num);
      normalize(p2, num);

      for (int j = 0; j < 4; j++) {
        if (eq(p1, q, num) || eq(p2, q, num)) {
          cout << i << endl;
          break;
        }
        kaiten(p1, num); kaiten(p2, num);
      }

    }

    cout << "+++++" << endl;
  }

  return 0;
}
