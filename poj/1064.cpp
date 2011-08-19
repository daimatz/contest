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

#define MAX_N 10000
#define MAX_K 10000
double L[MAX_N];
int N, K;

bool C(double len) {
  int cnt = 0;
  REP(i, N) {
    //DEBUG(L[i]); DEBUG(len); DEBUG(floor(L[i]/len));
    cnt += (int) floor(L[i]/len);
    if (cnt >= K)
      return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &N, &K);
  double total = 0;
  REP(i, N) {
    scanf("%lf", L+i);
    total += L[i];
  }

  double low = 0.00, high = total;
  while (high - low > EPS) {
    double mid = (high+low)/2;
    if (C(mid)) low = mid;
    else high = mid;
  }
  //printf("%.2f", floor(high*100)/100);
  printf("%.2f", high);
  return 0;
}
