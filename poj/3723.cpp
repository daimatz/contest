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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

typedef pair<int, int> Pii;
typedef pair<int, Pii> Piii;

#define MAX_N 10000
#define MAX_M 10000
#define MAX_R 50000

int N, M, R, V, E;
int x[MAX_R], y[MAX_R], d[MAX_R];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);

  while (T--) {
    scanf("%d %d %d", &N, &M, &R);
    while (R--) {
      int x, y, d;
      scanf("%d %d %d", &x, &y, &d);
      ::x[y] = ::y[x] = d;
    }
  }
  return 0;
}
