/*
 last updated: 2010/07/14 16:15:43
 */
#include <iostream>
#include <cstring>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  int n, s;
  cin >> n >> s;
  int a[n][n];
  memset(a, 0, sizeof(int));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      a[j][i] = s;
      s++;
      if (s == 10)
        s = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0)
        cout << " ";
      else
        cout << a[i][j];
      if (j != n-1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}
