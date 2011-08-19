/*
 last updated: 2010/08/24 03:08:58
 */
#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  int i = 0;
  while (1) {
    long long d;
    cin >> d;
    if (d == 0)
      break;
    long long k = 1;
    while (k < d) {
      k *= 10;
    }
    while (1) {
      d += k;
      if (d % 11 == 0 || d > k * 10 || d < 0)
        break;
    }
//    DEBUG(k);
    cout << ++i << ". ";
    if (d > k * 10)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << d/11 << endl;
  }
  return 0;
}
