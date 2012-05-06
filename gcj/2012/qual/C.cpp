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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

typedef pair<int, int> P;
set<P> S;

string to_s(int n) {
  char s[80];
  sprintf(s, "%d", n);
  return string(s);
}

int to_i(string s) {
  return atoi(s.c_str());
}

string cycle(string s, int n) {
  if (n <= 0 || (int)s.size() < n) return s;
  return (s.substr(s.size()-n, s.size()) + s.substr(0, s.size()-n));
}

int solve(int A, int B) {
  for (int a = A; a <= B; a++) {
    string s(to_s(a));
    for (uint i = 1; i < s.size(); i++) {
      string t = cycle(s, i);
      int si = to_i(s), ti = to_i(t);
      if (si < ti && ti <= B) S.insert(P(si, ti));
    }
  }
  return S.size();
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    S.clear();
    int A, B;
    scanf("%d %d", &A, &B);
    printf("Case #%d: %d\n", t, solve(A, B));
  }
  return 0;
}
