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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 1000

int N;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  vector<pair<int, int> > v(N);
  REP(i, N) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    v[a].first = v[b].second = i;
  }

  int ans = 0;
  REP(i, N) {
    for (int j = i+1; j < N; j++) {
      if ((v[i].first - v[j].first) * (v[i].second - v[j].second) < 0)
        ans++;
    }
  }

  printf("%d\n", ans);


  return 0;
}
