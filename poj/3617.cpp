/**
 * -*- coding: utf-8-unix -*-
 * last updated: 2010/11/22 03:26:54
 */

#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

void solve(string s, string t) {
  string r = "";
  if (s == "") {
    for (unsigned int i = 0; i < t.length(); i+=80) {
      cout << t.substr(i, 80) << endl;
    }
    return;
  }
  int len = s.length();
  for (int i = len - 1; i >= 0; i--)
    r += s[i];
  if (s < r) {
    t += r[len-1];
    r.erase(len-1);
    solve(r, t);
  } else {
    t += s[len-1];
    s.erase(len-1);
    solve(s, t);
  }
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    char s[n+1];
    for (int i = 0; i < n; i++)
      cin >> s[i];
    s[n] = '\0';
    string str(s);
    solve(s, "");
  }
  return 0;
}
