#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cerr<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

vector<int> ints;
vector<string> strs;
vector<bool> which; // false: int, true: string

bool number(const string &s) {
  bool flag = true;
  if (s[0] == '-' || ('0' <= s[0] && s[0] <= '9'))
    for (int i = 1; i < (int)s.size(); ++i)
      flag = flag && ('0' <= s[i] && s[i] <= '9');
  else
    flag = false;
  return flag;
}

string downcase(const string &s) {
  string ret;
  REP(i, s.size()) {
    if ('A' <= s[i] && s[i] <= 'Z')
      ret += s[i] - ('A' - 'a');
    else
      ret += s[i];
  }
  return ret;
}

bool comp(const string &s, const string &t) {
  return (downcase(s) < downcase(t));
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  while (1) {
    ints.clear();
    strs.clear();
    which.clear();
    while (1) {
      cin >> s;
      if (s == ".") break;
      t = s.substr(0, s.size()-1);
      //DEBUG(s);
      if (number(t)) {
        ints.push_back(atoi(t.c_str()));
        which.push_back(false);
      } else {
        strs.push_back(t);
        which.push_back(true);
      }

      if (s[s.size()-1] == '.') break;
    }
    sort(ALLOF(ints));
    //sort(ALLOF(strs), [](const string &s, const string &t) { return downcase(s) < downcase(t); }); // POJ doesn't support C++11...
    sort(ALLOF(strs), comp);

    //REP(i, ints.size()) DEBUG(ints[i]);
    //REP(i, strs.size()) DEBUG(strs[i]);

    int ii = 0, si = 0;
    REP(wi, which.size()) {
      if (!which[wi]) printf("%d", ints[ii++]);
      else printf("%s", strs[si++].c_str());
      if (wi == (int)which.size() - 1) printf(".\n");
      else printf(", ");
    }

    if (s == ".") break;
  }

  return 0;
}
