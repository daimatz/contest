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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

int A[40];

int main(int argc, char *argv[]) {

  int TESTN;
  scanf("%d\n", &TESTN);
  REP(T, TESTN) {
    int ans = 0;
    int n;
    scanf("%d\n", &n);
    memset(A, 0, sizeof(A));
    REP(i, n) {
      string s;
      cin >> s;
      int last = -1;
      REP(j, s.size()) {
        if (s[j] == '1')
          last = j;
      }
      A[i] = last;
    }

    REP(i, n) {
      int pos = -1;
      for (int j = i; j < n; j++) {
        if (A[j] <= i) {
          pos = j;
          break;
        }
      }

      for (int j = pos; j > i; j--) {
        swap(A[j], A[j-1]);
        ans++;
      }
    }

    printf("Case #%d: %d\n", T+1, ans);
  }

  return 0;
}
