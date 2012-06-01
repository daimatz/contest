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

int N, M, R;
map<int, vector<pair<int,int> > > S;
int ans[20000001];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d%d", &N, &M, &R);
  int x, y, z;
  REP(i, M) {
    scanf("%d%d%d", &x, &y, &z);
    if (S.count(y+R) == 0) S.insert(make_pair(y+R,vector<pair<int,int> >()));
    S[y+R].push_back(make_pair(x,z));
  }

  for (int i = 1; i <= N+R; i++) {
    int tmp = -1;
    if (S.count(i) > 0) {
      REP(j, S[i].size()) {
        if (tmp < ans[S[i][j].first] + S[i][j].second)
          tmp = ans[S[i][j].first] + S[i][j].second;
      }
    }
    ans[i] = max(ans[i-1], tmp);
  }

  //REP(i, N+R+1) printf("%d\n", ans[i]);

  printf("%d\n", ans[N+R]);

  return 0;
}
