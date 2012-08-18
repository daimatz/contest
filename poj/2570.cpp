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

int dist[210][210];

int n; // num of nodes

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (cin >> n) {
    if (n == 0) break;
    memset(dist, 0, sizeof(dist));

    int from, to;
    string companies;
    while (1) {
      cin >> from >> to;
      if (from + to == 0) break;
      --from; --to;

      cin >> companies;
      REP(i, companies.size()) {
        dist[from][to] |= 1 << (companies[i] - 'a');
      }
    }

    REP(k, n) REP(i, n) REP(j, n)
      dist[i][j] |= dist[i][k] & dist[k][j];

    while (1) {
      cin >> from >> to;
      if (from + to == 0) break;
      --from; --to;
      string ans;
      for (int c = 'a'; c <= 'z'; ++c) {
        if (dist[from][to] & (1 << (c - 'a')))
          ans += c;
      }
      if (ans.empty()) ans = "-";
      cout << ans << endl;
    }
    cout << endl;
  }

  return 0;
}
