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
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

int n;
int field[100][100];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

void dfs(int v, int x, int y) {
  field[x][y] = -1;
  REP(i, 4) {
    int nx = x+dx[i], ny = y+dy[i];
    if (0 <= nx && nx < n &&
        0 <= ny && ny < n &&
        field[nx][ny] == v)
      dfs(v, nx, ny);
  }
}

void solve() {
  REP(i, n) {
    bool flag = false;
    REP(j, n) {
      REP(k, n) {
        if (field[j][k] == i) {
          if (flag) {
            cout << "wrong" << endl;
            return;
          }
          dfs(field[j][k], j, k);
          flag = true;
        }
      }
    }
  }
  cout << "good" << endl;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    memset(field, 0, sizeof(field));
    int x, y;
    REP(i, n-1) {
      REP(j, n) {
        scanf("%d %d", &x, &y);
        field[x-1][y-1] = i+1;
      }
    }
    /**
     * REP(i, n) {
     *   REP(j, n) {
     *     cout << field[i][j] << " ";
     *   }
     *   cout << endl;
     * }
     */
    solve();
  }

  return 0;
}
