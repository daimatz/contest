/*
 last updated: 2010/06/04 00:52:42
 */
#include <iostream>
using namespace std;

string reverse(string s) {
  string r = "";
  for (int i = s.size() - 1; i >= 0; i--)
    r += s[i];
  return r;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = reverse(s2);
//    cout << s1 << s2 << s3 << endl;
    unsigned int i, j, k;
    i = j = k = 0;
    for (i = 0; i < s1.size(); i++) {
      if (s1[i] == s2[j]) j++;
      if (s1[i] == s3[k]) k++;
    }
    if (j == s2.size() || k == s3.size())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
