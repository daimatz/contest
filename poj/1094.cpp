/*
 last updated: 2010/06/24 22:46:17
 */
#include <iostream>
#include <list>
#include <queue>
using namespace std;

int find(string s, vector<string> v) {
  for (vector<string>::iterator it = v.begin();
       it != v.end();
       it++)
    if (s == *it)
      return 1;
  return 0;
}

int looped(string ss) {
  for (int i = 0; i < ss.length(); i++)
    for (int j = i + 1; j < ss.length(); j++)
      if (ss[i] == ss[j])
        return 1;
  return 0;
}

int next(vector<string> v, string ss, int n, int m, int cnt) {
  for (vector<string>::iterator jt = v.begin(); jt != v.end(); jt++) {
    if (ss.length() == n)
      return cnt;
    cnt++;
    if (ss[ss.length()-1] == (*jt)[0])
      next(v, ss+(*jt).substr(1), n, m, cnt);
  }
}

void solve(vector<string> v, int n, int m) {
  vector<string> ans;
  int determined = 0, cnt = 0;
  for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
    cnt = 0;
    string ss = *it;
    for (vector<string>::iterator jt = v.begin(); jt != v.end(); jt++) {
      cnt++;
      if (ss[ss.length()-1] == (*jt)[0])
        ss += (*jt).substr(1);
      if (ss.length() == n) {
        if (determined == 0)
          determined = cnt;
        else if (cnt < determined)
          determined = cnt;
      }
      if (looped(ss)) {
        cout << "Inconsistency found after " << cnt << " relations." << endl;
        return;
      }
    }
    if (ss.length() == n)
      ans.push_back(ss);
  }
  if (ans.size() == 1)
    cout << "Sorted sequence determined after " << determined << " relations: " << ans[0] << "." << endl;
  else
    cout << "Sorted sequence cannot be determined." << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
}

int main(int argc, char *argv[]) {
  int n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    vector<string> v;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      s.erase(1, 1);
      if (!find(s, v))
        v.push_back(s);
    }
    solve(v, n, m);
  }
  return 0;
}
