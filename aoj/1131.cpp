#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int x, y; // x / y
int cnt = 0;

#define MAX_N 7

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

bool rec(int p, int q, int a, int n, int m) {
  cout << "p = " << p << ", q = " << q << ", m = " << m << endl;
  if (n == 0) {
    if (p == 0)
      return true;
  }

  for (int i = m; i <= 800; i++) {
    if (!(a / i >= 1))
      return false;
    p = i*p-q;
    if (p < 0)
      return false;
    q = i*q;
    int t = gcd(p, q);
    p /= t;
    q /= t;
    if (rec(p, q, a/i, n-1, i))
      cnt++;
  }

}

int main(int argc, char *argv[]) {

  while (1) {
    cnt = 0;
    int p, q, a, n;
    scanf("%d %d %d %d", &p, &q, &a, &n);

    if (p == 0 && q == 0 && a == 0 && n == 0)
      break;

    for (int i = 1; i <= n; i++) {
      rec(p, q, a, i, 1);
    }

    cout << cnt << endl;

  }

  return 0;
}
