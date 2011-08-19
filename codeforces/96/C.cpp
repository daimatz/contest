#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

string in;

int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  string forbidden[n];
  string s[n];
  REP(i, n) {
    cin >> forbidden[n];
  }
  cin >> in;
  REP(i, n) {
    s[n] = in;
  }
  string r;
  cin >> r;

  REP(i, n) {
    s[i].replace(0, s[i].size(), r);
  }

  return 0;
}
