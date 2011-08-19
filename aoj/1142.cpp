#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

typedef pair<string, string> Pss;
set<string> ss;

int m;

int main(int argc, char *argv[]) {
  scanf("%d", &m);
  while (m--) {
    ss.clear();
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 1; i < len; i++) {
      string s1, s2, r1, r2;
      r1 = s1 = s.substr(0, i);
      r2 = s2 = s.substr(i, len-i);
      //DEBUG(s1); DEBUG(s2);
      reverse(ALLOF(r1));
      reverse(ALLOF(r2));
      ss.insert(s1+s2);
      ss.insert(s1+r2);
      ss.insert(r1+s2);
      ss.insert(r1+r2);
      ss.insert(s2+s1);
      ss.insert(s2+r1);
      ss.insert(r2+s1);
      ss.insert(r2+r1);
    }
    cout << ss.size() << endl;
  }
  return 0;
}
