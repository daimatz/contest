#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_W 20
#define MAX_H 20
typedef vector< vector<int> > Map;

struct Kyokumen {
  int x, y;
  Map m;
  int cnt;
  Kyokumen(Map m, int x, int y, int cnt) {
    this->m = m;
    this->x = x;
    this->y = y;
    this->cnt = cnt;
  }
};

int W, H;

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0)
      break;

    queue<Kyokumen> q;

    Map m;
    int sx, sy;
    REP(y, H) {
      vector<int> tmp;
      REP(x, W) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
          sx = x; sy = y;
          t = 0;
        }
        tmp.push_back(t);
      }
      m.push_back(tmp);
    }

    q.push(Kyokumen(m, sx, sy, 0));
    //DEBUG(p.first); DEBUG(p.second); continue;
    while (1) {

      Kyokumen *k = &q.front();
      q.pop();
      Map m = k->m;
      int sx = k->x, sy = k->y;
      int cnt = k->cnt;

      int xs[] = {1,0,-1,0}, ys[] = {0,1,0,-1};
      bool flag = false;
      REP(i, 4) {
        int x = sx+xs[i], y = sy+ys[i];
        //DEBUG(x); DEBUG(y);
        if (!(0 <= x && x < W && 0 <= y && y < H) ||  m[y][x] == 1)
          continue;
        while (1) {
          //DEBUG(x); DEBUG(y);
          if (!(0 <= x && x < W && 0 <= y && y < H))
            break;
          if (m[y][x] == 3) {
            flag = true;
            break;
          }
          if (m[y][x] == 1) {
            m[y][x] = 0;
            //q.push(Kyokumen(m, Pii(x-xs[i], y-ys[i])));
            q.push(Kyokumen(m, x-xs[i], y-ys[i], cnt+1));
          }
          x += xs[i]; y += ys[i];
        }
        if (flag) break;
      }
      if (flag) {
        cout << cnt << endl;
        break;
      }

      if (q.empty() || cnt == 10) {
        cout << -1 << endl;
        break;
      }
    }
  }

  return 0;
}
