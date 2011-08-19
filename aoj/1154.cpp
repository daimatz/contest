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
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 300000

int n;

vector<int> v;
int table[MAX_N+1];

int main(int argc, char *argv[]) {

  REP(i, MAX_N+1) {
    if (!(i % 7 == 6 || i % 7 == 1))
      table[i] = 1;
  }

  REP(i, MAX_N+1) {
    if (i == 0 || i == 1) table[i] = 1;
    if (!table[i]) {
      for (int j = i*2; j < MAX_N+1; j+= i)
        table[j] = 1;
    }
  }

  /**
   * REP(i, MAX_N+1) {
   *   if (!table[i])DEBUG(i);
   *   if (i == 100)break;
   * }return 0;
   */

  while (1) {
    scanf("%d", &n);
    if (n == 1)
      break;

    v.clear();
    REP(i, n+1) {
      if (!table[i] && n % i == 0) {
        v.push_back(i);
      }
    }


    printf("%d: ", n);
    FOR(i, v) {
      if (i+1 == v.end())
        printf("%d", *i);
      else
        printf("%d ", *i);
    }
    puts("");
  }
  return 0;
}
