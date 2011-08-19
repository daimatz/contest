/*
 last updated: 2010/07/06 18:39:46
 */
#include <iostream>
using namespace std;

int pow(int d, int p) {
  int ret = 1;
  if (p == 0)
    return 1;
  while (p--)
    ret *= d;
  return ret;
}

int main(int argc, char *argv[]) {
  int n, p, sum = 0;
  cin >> n >> p;
  while (n--) {
    int d, k;
    cin >> d;
    k = pow(d, p);
    if (k > 0)
      sum += k;
  }
  cout << sum << endl;
  return 0;
}
