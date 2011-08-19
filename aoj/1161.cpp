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

#define MAX_N 12
int N;

string s[MAX_N];

set<char> ss;
int f[(int)'Z'];

int conv(string s) {
  int ret = 0;
  int len = s.size();
  REP(i, len) {
    ret = ret*10 + f[(int)s[len-1-i]];
  }
  return ret;
}

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d", &N);
    if (N == 0) break;
    ss.clear();
    REP(i, N) {
      cin >> s[i];
      REP(j, s[i].size())
        ss.insert(s[i][j]);
    }

  }
  return 0;
}
