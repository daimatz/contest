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

#define INF (LLONG_MAX/10-1)
#define EPS (1.0e-8)

struct P {
  int score, cost;
  P(int score, int cost) : score(score), cost(cost) {}
  bool operator<(const P &a) const {
    return score < a.score;
  }
};

int N, C;
ll F;
vector<P> v;

int solve() {
  sort(ALLOF(v));

  ll low[100000], high[100000];

  priority_queue<ll> q;
  ll acc = 0;
  REP(i, C) {
    low[i] = (int)q.size() == N/2 ? acc : INF;
    acc += v[i].cost;
    q.push(v[i].cost);
    if ((int)q.size() > N/2) {
      acc -= q.top();
      q.pop();
    }
  }

  q = priority_queue<ll>();
  acc = 0;

  for (int i = C-1; i >= 0; --i) {
    high[i] = (int)q.size() == N/2 ? acc : INF;
    acc += v[i].cost;
    q.push(v[i].cost);
    if ((int)q.size() > N/2) {
      acc -= q.top();
      q.pop();
    }
  }

  for (int i = C-1; i >= 0; --i)
    if (v[i].cost + low[i] + high[i] <= F)
      return v[i].score;

  return -1;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d%d%lld", &N, &C, &F);
  REP(i, C) {
    int s, c;
    scanf("%d%d", &s, &c);
    v.push_back(P(s,c));
  }

  printf("%d\n", solve());

  return 0;
}
