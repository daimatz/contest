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

bool f(char c) {
  switch (c) {
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
  case 'g':
  case 'q':
  case 'r':
  case 's':
  case 't':
  case 'v':
  case 'w':
  case 'x':
  case 'z':
    return true;
  default:
    return false;
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    string in;
    cin >> in;
    if (in == "#") break;
    int cnt = 0;
    bool flag = f(in[0]);
    REP(i, in.size()) {
      if (flag != f(in[i])) {
        cnt++;
        flag = !flag;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
