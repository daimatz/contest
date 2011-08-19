/*
 last updated: 2010/05/21 12:40:32
 */
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
  int t, n, s;
  cin >> t;
  for (int i = 0; i<t; i++) {
    cin >> n;
    string ss;
    ss = "";
    // P-sequence -> S
    for (int j = 0; j<n; j++) {
      cin >> s;
      while (ss.length() - j != s) {
        ss += "(";
      }
      ss += ")";
    }
    // S -> W-sequence
    for (int j = 0; j<n; j++) {
      int k;
      for (k = 0; ss[k] != ')'; k++)
        ;
      ss[k] = '_';
      k--;
      int l;
      for (l = 0; ss[k-l] != '('; l++)
        ;
      ss[k-l] = '_';
      cout << (l/2)+1 << " ";
    }
    cout << endl;
  }
  return 0;
}
