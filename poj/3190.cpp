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

struct P {
  int s, e, i;
  P() {}
  P(int s, int e, int i) : s(s), e(e), i(i) {}
  bool operator<(const P &a) const {
    return s < a.s || (s == a.s && e < a.e);
  }
};

P v[50000];
int ans[50000];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  int s, e;
  priority_queue<pair<int, int> > barns;
  cin >> N;
  REP(i, N) {
    cin >> s >> e;
    v[i] = P(s,e,i);
  }
  sort(v,v+N);
  int num = 0;
  REP(i, N) {
    if (barns.empty() || v[i].s <= -barns.top().first) {
      ++num;
      barns.push(make_pair(-v[i].e, num));
      ans[v[i].i] = num;
    } else {
      ans[v[i].i] = barns.top().second;
      barns.pop();
      barns.push(make_pair(-v[i].e, ans[v[i].i]));
    }
  }
  cout << num << endl;
  REP(i, N) cout <<  ans[i] << endl;

  return 0;
}
