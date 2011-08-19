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

// T = F { (*|+) F }
// F = (T) | -F | 0 | 1 | 2

typedef pair<int, const char*> parsed;

string in;

parsed f(const char *p);
parsed t(const char *p);

parsed pls(int n, const char *p) {
  parsed r = f(p);
  if (n == 2) return parsed(2, r.second);
  if (n == 1) {
    if (r.first == 2) return parsed(2, r.second);
    return parsed(1, r.second);
  }
  return parsed(r.first, r.second);
}

parsed mpl(int n, const char *p) {
  parsed r = f(p);
  if (n == 2) return parsed(r.first, r.second);
  if (n == 1) {
    if (r.first == 0) return parsed(0, r.second);
    return parsed(1, r.second);
  }
  return parsed(0, r.second);
}

parsed f(const char *p) {
  if (*p == '(') {
    p++;
    parsed r = t(p);
    if (*r.second != ')') exit(1);
    return parsed(r.first, r.second+1);
  } else if (*p == '-') {
    p++;
    parsed r = f(p); // not t(p)
    //printf("%d %s\n", r.first, r.second);
    //printf("%d %c\n", r.first, *r.second+1);
    int x;
    if (r.first == 2) x = 0;
    else if (r.first == 1) x = 1;
    else if (r.first == 0) x = 2;
    else { DEBUG(r.first); exit(1); }
    return parsed(x, r.second);
  } else if (isdigit(*p)) {
    int x = *p++ - '0';
    return parsed(x, p);
  }
}

parsed t(const char *p) {
  parsed r = f(p);
  if (*r.second == '+') {
    return pls(r.first, r.second+1);
  } else if (*r.second == '*') {
    return mpl(r.first, r.second+1);
  } else {
    DEBUG(*r.second);
    DEBUG("invalid!");
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    cin >> in;
    if (in == ".") break;

    //DEBUG(in);
    int cnt = 0;
    REP(i,3) REP(j,3) REP(k,3) {
      string s = in;
      REP(x, s.size()) {
        if (s[x] == 'P') s[x] = i+'0';
        if (s[x] == 'Q') s[x] = j+'0';
        if (s[x] == 'R') s[x] = k+'0';
      }
      //printf("%d %d %d -> %s\n", i,j,k,s.c_str());
      parsed t = f(s.c_str());
      //printf("%s = %d\n",s.c_str(),t.first);
      if (t.first == 2)
        cnt++;
    }

    cout << cnt << endl;
  }
  return 0;
}
