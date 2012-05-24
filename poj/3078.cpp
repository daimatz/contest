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

  int x;
  cin >> x;
  while (x--) {
    int m, n;
    cin >> m >> n;
    vector<string> in(m), out(m);
    fill(ALLOF(out), "");
    REP(i, m) cin >> in[i];
    REP(i, n) {
      int from, to;
      cin >> from >> to;
      out[to-1] = in[from-1];
      in[from-1] = "";
    }
    REP(i, m) {
      if (in[i] != "") {
        REP(j, m) {
          if (out[j] == "") {
            out[j] = in[i];
            in[i] = "";
            break;
          }
        }
        in[i] = "";
      }
    }
    REP(i, m) {
      cout << out[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
