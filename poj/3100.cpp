/*
 last updated: 2010/07/13 03:52:05
 */
#include <iostream>
#define DEBUG(x) cout<< "line:"<<__LINE__ <<", "<<#x" == " << x << endl;
#define MAX 1000000
using namespace std;

int pow(int i, int k) {
  int ret = 1;
  while (k--)
    ret *= i;
  return ret;
}

int rt(int n, int k) {
  int i, ret = 1;
  for (i = 1; ret <= n; i++)
    ret = pow(i, k);
  i--;
  //DEBUG(i); DEBUG(ret); DEBUG(n); DEBUG(k);
  if (n-pow(i-1,k) < ret-n)
    i--;
  return i;
}

int main(int argc, char *argv[]) {
  while (true) {
    int b, n;
    cin >> b >> n;
    if (b == 0 && n == 0)
      break;
    cout << rt(b, n) << endl;
  }
  return 0;
}
