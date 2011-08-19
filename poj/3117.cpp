/*
 last updated: 2010/07/07 11:54:14
 */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  while (true) {
    int t, n;
    cin >> t >> n;
    if (t == 0 && n == 0)
      break;
    int sum = 0;
    while (t--) {
      string s;
      int p;
      cin >> s >> p;
      sum += p;
    }
    cout << 3*n - sum << endl;
  }
  return 0;
}
