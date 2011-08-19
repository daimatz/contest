#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin())it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_W 30
#define MAX_H 30
int W, H;

int maze[MAX_H][MAX_W];
int cost[4];

int dx[4] = {1,0,-1,0}, dy[] = {0,1,0,-1};

inline int toNode(int x, int y, int d, int w) {
  return ((y*w)+x)*4+d;
}

struct Edge {
  int from, to, cost;
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

inline bool operator>(const Edge &a, const Edge &b) {
  return a.cost > b.cost;
}

int main(int argc, char *argv[]) {

  while (1) {
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0) break;
    REP(i, H) {
      REP(j, W) {
        scanf("%d", &maze[i][j]);
      }
    }
    REP(i, 4) {
      scanf("%d", cost+i);
    }

    Graph g;
    REP(y,H) REP(x,W) REP(d,4) {
      Edges es;
      int cur = toNode(x,y,d,W);

      REP(cmd, 4) {
        int toD = (d+cmd)%4;
        int toX = x+dx[toD], toY = y+dy[toD];
        if (toX < 0 || toX >= W || toY < 0 || toY >= H)
          continue;
        int next = toNode(toX, toY, toD, W);

        int weight = (maze[x][y] == cmd) ? 0 : cost[cmd];
        es.push_back((Edge){cur,next,weight});
      }
      g.push_back(es);
    }

    priority_queue<Edge, vector<Edge>, greater<Edge> >q;
    q.push((Edge){-1,0,0});
    bool visited[W*H*4];
    memset(visited, 0, sizeof(visited));
    int goal = toNode(W-1,H-1,0,W/4);
    int ret = -1;

    while (!q.empty()) {
      Edge e = q.top(); q.pop();
      if (visited[e.to])
        continue;
      visited[e.to] = true;
      if (e.to/4 == goal) {
        ret = e.cost;
        break;
      }
      FOR(it, g[e.to]) {
        if (!visited[it->to])
          q.push((Edge){it->from, it->to, it->cost + e.cost});
      }
    }

    cout << ret << endl;

  }

  return 0;
}
