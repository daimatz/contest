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
#include <list>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

int main(int argc, char *argv[]) {
  int N, K, P;
  cin >> N >> K >> P;
  list<int> v;

  REP(i, K) v.push_back(i+1);
  list<int>::iterator it = v.begin();

  vector<int> ans;

  int i = 0;
  while (1) {
    int t = *it;
    it = v.erase(it);
    if (it == v.end()) it = v.begin();
    if (++i % N == 0) ans.push_back(t);
    if (v.empty()) break;

    REP(i, P) {
      it++;
      if (it == v.end()) it = v.begin();
    }
  }
  sort(ALLOF(ans));
  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }
  return 0;
}
