/*
 last updated: 2010/06/04 15:48:00
 */
#include <iostream>
using namespace std;

int update(int ans[11], int n, string s) {
  if (s == "high") {
    for (int i = n; i <= 10; i++)
      ans[i] = 0;
    return -1;
  }
  if (s == "low") {
    for (int i = 1; i <= n; i++)
      ans[i] = 0;
    return -1;
  }
  if (s == "on") {
    return ans[n];
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    int n;
    int ans[11];
    for (int i = 1; i <= 10; i++)
      ans[i] = 1;
    while (1) {
      int d;
      string s, t;
      cin >> n;
      if (n == 0)
        return 0;
      cin >> s >> t;
      if ((d = update(ans, n, t)) >= 0) {
        if (d == 0)
          cout << "Stan is dishonest" << endl;
        else
          cout << "Stan may be honest" << endl;
        break;
      }
    }
  }
  return 0;
}
