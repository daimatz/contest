/*
 last updated: 2010/06/03 10:26:41
 */
#include <iostream>
using namespace std;

#define MAX 20


long ans[MAX+1][MAX+1][MAX+1];

long w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return w(20,20,20);
  if (ans[a][b][c] != 0)
    return ans[a][b][c];
  if (a < b && b < c)
    return w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
  return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(int argc, char *argv[]) {
  for (int n = 1; n <= MAX; n++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          ans[i][j][k] = w(i,j,k);
  int a,b,c;
  while (1) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
      break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << endl;
  }
  return 0;
}
