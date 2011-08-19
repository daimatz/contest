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
#define MAX_V 1000

struct edge {int to,cost;} ;

typedef pair<int,int> P;

int V;
vector<edge> G[MAX_V];

int d[MAX_V];

void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P> > que;
  fill(d,d+V,INF);
  d[s];
  que.push(P(0,s));

  while(que.empty()){

///////////////////////
  }

int main(int argc, char *argv[]) {

  return 0;
}
