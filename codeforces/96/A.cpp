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

int main(int argc, char *argv[]) {

  string s;
  cin >> s;

  /**
   * bool flag = false;
   * REP(i, s.size()) {
   *   if (s[i] == '0') {
   *     for (int j = i+1; j < (int)s.size(); j++) {
   *       if (s.substr(j,7) == "1111111") {
   *         flag = true;
   *         break;
   *       }
   *     }
   *   } else if (s[i] == '1') {
   *     for (int j = i+1; j < (int)s.size(); j++) {
   *       if (s.substr(j,7) == "0000000") {
   *         flag = true;
   *         break;
   *       }
   *     }
   *   }
   * }
   * cout << (flag ? "YES" : "NO") << endl;
   */

  string::size_type i1 = s.find("1111111"), i2 = s.find("0000000");
  if (i1 == string::npos && i2 == string::npos) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}
