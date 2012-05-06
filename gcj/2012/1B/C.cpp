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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

vector<vector<int> > solve(vector<int> S) {
  sort(S.begin(), S.end());
  for (int B1 = 1; B1 < (1<<20)-1; B1++) {
    int S1 = 0;
    vector<int> M1;
    for (int i = 0; i < 20; i++) {
      if ((B1 >> i) & 1) {
        S1 += S[i];
        M1.push_back(S[i]);
      }
    }
    for (int B2 = 0; B2 < (1<<20)-1; B2++) {
      if (((B1 & B2) != 0) || B1 == 0 || B2 == 0) continue;
      int S2 = 0;
      vector<int> M2;
      for (int i = 0; i < 20; i++) {
        if ((B2 >> i) & 1) {
          S2 += S[i];
          M2.push_back(S[i]);
          if (S2 > S1) break;
        }
        if (S2 > S1) break;
        if (S1 == S2) {
          vector<vector<int> > ret;
          ret.push_back(M1);
          ret.push_back(M2);
          return ret;
        }
      }
    }
  }
  return vector<vector<int> >();
}

int main(int argc, char *argv[]) {

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    vector<int> S;
    for (int i = 0; i < N; i++) {
      int tmp;
      scanf("%d", &tmp);
      S.push_back(tmp);
    }
    vector<vector<int> > m = solve(S);
    printf("Case #%d:\n", t);
    if (m.empty()) {
      printf("Impossible\n");
    } else {
      for (uint i = 0; i < m[0].size(); i++)
        printf("%d ", m[0][i]);
      puts("");
      for (uint i = 0; i < m[1].size(); i++)
        printf("%d ", m[1][i]);
      puts("");
    }
  }

  return 0;
}
