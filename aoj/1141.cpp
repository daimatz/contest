// AOJ 1141
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

#define MAX_N 1000000
int prime[MAX_N+1];

int main(int argc, char *argv[]) {

  memset(prime, -1, sizeof(prime));
  prime[0] = prime[1] = 0;
  REP(n, MAX_N+1) {
    if (prime[n])
      for (int i = n*2; i < MAX_N+1; i += n) {
//        DEBUG(i);
        prime[i] = false;
      }
  }

  while (1) {
    int a, d, n;
    scanf("%d %d %d", &a, &d, &n);
    if (a == 0 && d == 0 && n == 0)
      break;
    REP(i, INF) {
      if (prime[a + d * i])
        n--;
      if (n == 0) {
        printf("%d\n", a+d*i);
        break;
      }
    }
  }

  return 0;
}
