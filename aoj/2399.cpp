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

int N;
vector<set<int>> I(N);
vector<int> R;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    scanf("%d", &N);
    if (N == 0) break;
    I.clear();
    I.resize(N);
    REP(i, N) {
      int m;
      scanf("%d", &m);
      REP(j, m) {
        int tmp;
        scanf("%d", &tmp);
        --tmp;
        I[i].insert(tmp);
      }
    }
    int k;
    scanf("%d", &k);
    R.resize(k);
    REP(i, k) {
      scanf("%d", &R[i]);
      --R[i];
    }
    vector<int> ans;
    REP(i, I.size()) {
      int flag = true;
      REP(j, R.size()) {
        if (I[i].count(R[j]) == 0) {
          flag = false;
          break;
        }
      }
      if (flag) ans.push_back(i);
    }
    if (ans.size() == 1) printf("%d\n", ans[0]+1);
    else puts("-1");
  }

  return 0;
}
