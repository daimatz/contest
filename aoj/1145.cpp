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

#define isnum(s) (((s)-'0') <= 9)
#define c2d(s) ((int)((s)-'0'))

string parse(string s) {
  string t;
  REP(i, s.size()) {

  }
}

int main(int argc, char *argv[]) {
  string in;
  int d;

  while (1) {
    cin >> in >> d;
    int len = in.size();
    REP(i, len) {
      int d = 0;
      for (int j = 1; isnum(in[i]); i++, j *= 10) {
        d += c2d(in[i]) * j;
      }
    }
  }
  return 0;
}
