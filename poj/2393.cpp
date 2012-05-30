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

int C[10000], Y[10000];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, S;
  scanf("%d%d", &N, &S);
  int mi = 0;
  ll cost = 0;
  REP(i, N) {
    //DEBUG(cost);
    scanf("%d%d", C+i, Y+i);
    if ((i-mi)*S < C[i] - C[mi]) {
      cost += C[mi] * Y[i];
      cost += (i-mi) * S * Y[i];
    } else {
      cost += C[i] * Y[i];
      mi = i;
    }
  }
  printf("%lld\n", cost);

  return 0;
}
