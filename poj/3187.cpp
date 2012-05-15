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
#define EPS (1.0e-8)

int N, S;

bool check(int P[]) {
  REP(i, N) {
    int Q[N-i-1];
    REP(j, N-i-1) {
      Q[j] = (P[j]+P[j+1]);
    }
    memcpy(P, Q, sizeof(Q));
  }
  return P[0] == S;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  scanf("%d %d", &N, &S);

  int P[N];
  REP(i, N) P[i] = i+1;

  int Q[N];
  do {
    memcpy(Q, P, sizeof(P));
    if (check(Q))
      break;
  } while (next_permutation(P, P+N));

  REP(i, N)
    printf("%d ", P[i]);
  puts("");

  return 0;
}
