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

int N;
int v[2000];

int memo[2000][2000];

int ans(int start, int end) {
  if (memo[start][end]) return memo[start][end];
  int age = N - (end - start);
  if (start == end) {
    return (memo[start][end] = v[start] * age);
  } else {
    return (memo[start][end] = max(v[start]*age + ans(start+1, end),
                                   v[end]*age + ans(start, end-1)));
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", v+i);
  printf("%d\n", ans(0,N-1));

  return 0;
}
