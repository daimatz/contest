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

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s;
  while (N--) {
    cin >> s;
    int c = 0;
    for (int i = s.size()-1; i >= 1; i--) {
      if (s[i] + c >= '5') {
        c = 1;
        s[i] = '0';
      } else {
        c = 0;
        s[i] = '0';
      }
    }
    if (s[0] == '9' && c == 1) {
      s[0] = '0';
      s = "1" + s;
    } else {
      s[0] = s[0] + c;
    }
    cout << s << endl;
  }

  return 0;
}
