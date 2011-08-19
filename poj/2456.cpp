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

#define MAX_N 100000
#define MAX_M 100000
int N, M;
int x[MAX_N];

bool C(int d) {
  int last = 0;
  for (int i = 1; i < M; i++) {
    int crt = last + 1;
    while (crt < N && x[crt] - x[last] < d) {
      crt++;
    }
    if (crt == N)
      return false;
    last = crt;
  }
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &M);

  REP(i, N) {
    scanf("%d", x+i);
  }
  sort(x, x+N);

  int low = 0, high = INF;
  while (high - low > 1) {
    int mid = (high+low) / 2;
    if (C(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << low << endl;

  return 0;
}
