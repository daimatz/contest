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

int t, n;
long long k;

int main(int argc, char *argv[]) {

  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> v;
    v.push_back(k);
    if (n == 1) {
      cout << k << endl;
      continue;
    }
    int c = 0;
    while (1) {
      //if (cnt++ == 20) break;
      int tmp = n * v.back() + c;
      c = (tmp - (tmp%10)) / 10;
      tmp = tmp%10;
      v.push_back(tmp);
      //DEBUG(tmp);
      if (tmp * n + c == v.front()) {
        if (v.back() == 0) {
          cout << 0 << endl;
          /**
           * for (int i = v.size()-1; i >= 0; i--)
           *   cout << v[i];
           * cout << endl;
           */
          break;
        } else {
          for (__typeof(v.rbegin()) it = v.rbegin();
               it != v.rend();
               it++) {
            cout << *it;
          }
          //cout << v[5] << v[4] << v[3] << v[2] << v[1] << v[0];
          cout << endl;
          break;
        }
      }
    }
  }

  return 0;
}
