/*
 last updated: 2010/06/02 02:20:23
 */
#include <iostream>
#define MAX 1000000

using namespace std;

int ok(int d) {
  int k[8] = {0,0,0,0,0,0,0,0};
  int u[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int p = 0;
  while (d > 0) {
    int i = d % 10;
    k[p] = i;
    if (u[i] != -1)
      return u[i];
    u[i] = p;
    p++;
    d = (d-i) / 10;
  }
  return -1;
}

int pow(int x, int n) {
  int ret = 1;
  while (n--)
    ret *= x;
  return ret;
}

int main(int argc, char *argv[]) {
  int a[MAX+1];
  int n, ans = 0, p;
  for (int i = 1; i < MAX+1; i++) {
    ans++;
    while ((p = ok(ans)) != -1)
      ans += pow(10, p);
    a[i] = ans;
  }
  while (cin >> n) {
    if (n == 0) break;
    cout << a[n] << endl;
  }
  return 0;
}
