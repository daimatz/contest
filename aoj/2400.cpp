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

int T,P,R;
int wa[50][10];

struct K {
  ll team, ac, pen;
  bool operator<(const K &a) const {
    return (ac > a.ac) || (ac == a.ac && pen < a.pen)
      || (ac == a.ac && pen == a.pen && team < a.team);
  }
};

vector<K> S;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (1) {
    cin >> T >> P >> R;
    if (T == 0 && P == 0 && R == 0) break;

    memset(wa, 0, sizeof(wa));
    S.resize(T);
    REP(i, T) {
      S[i].team = i;
      S[i].ac = S[i].pen = 0;
    }
    REP(i, R) {
      int team, prob, time;
      string mes;
      cin >> team >> prob >> time >> mes;
      --team; --prob;
      if (mes == "WRONG") ++wa[team][prob];
      else {
        ++S[team].ac;
        S[team].pen += wa[team][prob] * 1200 + time;
      }
    }
    sort(ALLOF(S));
    REP(i, T) {
      cout << S[i].team+1 <<" " << S[i].ac <<" " << S[i].pen << endl;
    }
  }

  return 0;
}
