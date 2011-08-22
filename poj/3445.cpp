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

string m[16];

int main(int argc, char *argv[]) {
  m[0] = "{}";
  m[1] = "{{}}";
  for (int i = 2; i < 16; i++) {
    m[i] = m[i-1].substr(0, m[i-1].size()-1) + "," + m[i-1] + "}";
  }

  int n;
  cin >> n;

  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;
    //DEBUG(s1); DEBUG(s2);
    int n1, n2;
    REP(i, 16) {
      if (m[i] == s1) n1 = i;
      if (m[i] == s2) n2 = i;
    }
    cout << m[n1+n2] << endl;
  }

  return 0;
}
