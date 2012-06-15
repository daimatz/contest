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

int npr[10001];
vector<int> pr;
int ans;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  npr[0] = npr[1] = true;
  REP(i, 10001) {
    if (i < 2) continue;
    if (!npr[i]) {
      pr.push_back(i);
      for (int j = i*2; j < 10001; j+=i)
        npr[j] = true;
    }
  }

  int n;
  while (cin >> n && n) {
    ans = 0;
    REP(start, pr.size()) {
      int t = n;
      for (int i = start; t > 0; ++i) {
        t -= pr[i];
      }
      if (t == 0) ++ans;
    }
    cout << ans << endl;
  }

  return 0;
}
