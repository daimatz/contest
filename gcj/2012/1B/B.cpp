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
#define EPS 1.0e-8

struct DIR {
  int dx, dy;
  DIR(int _dx, int _dy) { dx = _dx; dy = _dy; }
};

struct PATH {
  vector<DIR> d;
  int x, y;
  double t;
  bool operator<(const PATH &a) const {
    return t > a.t; // 小さい順
  }
  PATH(vector<DIR> _d, int _x, int _y, double _t) {
    x = _x; y = _y;
    d = _d, t = _t;
  }
  void print() {
    cerr << "d: ";
    for (uint i = 0; i < d.size(); i++) {
      cerr << "(" << d[i].dx << "," << d[i].dy << "),";
    }
    cerr << "; (x, y) = (" << x << ", " << y << "), t = " << t << endl;
  }
};

double solve(int H, vector<vector<int>> C, vector<vector<int>> F) {
  priority_queue<PATH> q;
  q.push(PATH(vector<DIR>(), 0, 0, 0.0));
  set<pair<int, int>> CC;
  while (!q.empty()) {
    PATH p = q.top(); q.pop();
    if (CC.find(pair<int, int>(p.x, p.y)) != CC.end()) continue;
    CC.insert(pair<int, int>(p.x, p.y));
    double curH = H - p.t * 10;
    //p.print(); cerr << "curH: " << curH << ", C: " << C[p.x][p.y] << ", F: " << F[p.x][p.y] << endl;
    if (p.x == (int)C.size()-1 && p.y == (int)C[0].size()-1) return p.t;
    int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
    for (int i = 0; i < 4; i++) {
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if (0 <= nx && nx < (int)C.size()
          && 0 <= ny && ny < (int)C[0].size()
          && C[p.x][p.y] - F[nx][ny] >= 50
          && C[nx][ny] - F[p.x][p.y] >= 50
          && C[nx][ny] - F[nx][ny] >= 50) {
        vector<DIR> d = p.d;
        d.push_back(DIR(nx,ny));
        if (p.t == 0.0 && C[nx][ny] - curH >= 50) {
          q.push(PATH(d, nx, ny, p.t));
        } else {
          double nt = p.t;
          if (C[nx][ny] - curH < 50) nt += (50 - (C[nx][ny] - curH)) * 0.1;
          //DEBUG(nt);
          if ((curH - (nt-p.t)*10.0) - F[p.x][p.y] < 20) {
            q.push(PATH(d, nx, ny, nt+10.0));
          } else {
            q.push(PATH(d, nx, ny, nt+1.0));
          }
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int H, N, M;
    scanf("%d %d %d", &H, &N, &M);
    vector<vector<int>> C, F;
    for (int i = 0; i < N; i++) {
      vector<int> tmp;
      for (int j = 0; j < M; j++) {
        int k;
        scanf("%d", &k);
        tmp.push_back(k);
      }
      C.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
      vector<int> tmp;
      for (int j = 0; j < M; j++) {
        int k;
        scanf("%d", &k);
        tmp.push_back(k);
      }
      F.push_back(tmp);
    }
    /**
     * fprintf(stderr, "\n");
     * fprintf(stderr, "       ");
     * REP(j, C[0].size()) fprintf(stderr, "%4d ", j);
     * fprintf(stderr, "\n");
     * REP(j, C[0].size()+1) fprintf(stderr, "-----");
     * fprintf(stderr, "\n");
     * REP(i, C.size()) {
     *   fprintf(stderr, "%4d | ", i);
     *   REP(j, C[0].size()) fprintf(stderr, "%4d ", C[i][j]);
     *   fprintf(stderr, "\n");
     *   fprintf(stderr, "     | ");
     *   REP(j, C[0].size()) fprintf(stderr, "%4d ", F[i][j]);
     *   fprintf(stderr, "\n\n");
     * }
     */
    printf("Case #%d: %.1f\n", t, solve(H, C, F));
  }
  return 0;
}
