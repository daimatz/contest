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

int N, M;
string ID;
int C[26];

int ans[2000][2000];

int solve(int x, int y) {
  if (ans[x][y] != -1) return ans[x][y];
  if (x >= y) ans[x][y] = 0;
  else if (ID[x] == ID[y]) ans[x][y] = solve(x+1, y-1);
  else ans[x][y] = min(solve(x, y-1) + C[ID[y]-'a'],
                       solve(x+1, y) + C[ID[x]-'a']);
  return ans[x][y];
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  cin >> ID;
  REP(i, N) {
    string c;
    int x, y;
    cin >> c >> x >> y;
    C[c[0]-'a'] = min(x,y);
  }

  memset(ans, -1, sizeof(ans));

  cout << solve(0, M-1) << endl;

  return 0;
}
