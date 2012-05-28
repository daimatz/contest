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

int maze[5][5];
set<string> st;
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};

void dfs(int x, int y, int n, string s) {
  if (n == 6) {
    st.insert(s);
    return;
  }
  s += (char)('0'+maze[x][y]);
  REP(i, 4) {
    int nx = x+dx[i], ny = y+dy[i];
    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
      dfs(nx,ny,n+1,s);
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 5) REP(j, 5) scanf("%d", &maze[i][j]);
  REP(i, 5) REP(j, 5) dfs(i,j,0,"");
  printf("%d\n", (int)st.size());
  return 0;
}
