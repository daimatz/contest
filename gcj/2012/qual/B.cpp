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

int ans;

bool is_suprising(vector<int> tripet) {
  int min = 11, max = -1;
  for (uint i = 0; i < tripet.size(); i++) {
    if (tripet[i] < min) min = tripet[i];
    if (tripet[i] > max) max = tripet[i];
    if (max - min == 2) return true;
  }
  return false;
}

int max_score(vector<int> tripet) {
  int max = -1;
  for (uint i = 0; i < tripet.size(); i++)
    if (tripet[i] > max)
      max = tripet[i];
  return max;
}

void solve(int S, int p, vector<int> Sums, vector<vector<int> > Tripets) {
  for (int i = 0; i < Sums.size(); i++) {
    int base;
    if ((base = Sums[i] / 3) >= p) {
      ans++;
    } else {
      if (S > 0) {
        switch (Sums[i] % 3) {
        case 0:
        case 1:
          if (base > 0 && p-1 == base) {
            ans++;
            S--;
          }
          break;
        case 2:
          if (p-1 == base) {
            ans++;
            S--;
          }
          break;
        }
      }
    }
  }
  /**
   * if (Sums.empty()) {
   *   /\**
   *    * cout << "====== S: " << S << ", p: " << p << "=====" << endl;
   *    * for (int i = 0; i < Tripets.size(); i++) {
   *    *   cout << Tripets[i][0] << ' ' << Tripets[i][1] << ' ' << Tripets[i][2] << endl;
   *    * }
   *    *\/
   *   if (S > 0) return;
   *   int tmp = 0;
   *   for (uint i = 0; i< Tripets.size(); i++)
   *     if (max_score(Tripets[i]) >= p)
   *       tmp++;
   *   if (tmp > ans)
   *     ans = tmp;
   *   return;
   * }
   *
   * int Sum = Sums[0]; Sums.erase(Sums.begin());
   * int base = Sum / 3;
   * vector<int> t1, t2;
   * switch (Sum % 3) {
   * case 0:
   *   t1.push_back(base); t1.push_back(base); t1.push_back(base);
   *   Tripets.push_back(t1); solve(S, p, Sums, Tripets);
   *   if (S > 0 && base >= 1) {
   *     t2.push_back(base-1); t2.push_back(base); t2.push_back(base+1);
   *     Tripets.pop_back();
   *     Tripets.push_back(t2); solve(S-1, p, Sums, Tripets);
   *   }
   *   return;
   * case 1:
   *   t1.push_back(base); t1.push_back(base); t1.push_back(base+1);
   *   Tripets.push_back(t1); solve(S, p, Sums, Tripets);
   *   if (S > 0 && base >= 1) {
   *     t2.push_back(base-1); t2.push_back(base+1); t2.push_back(base+1);
   *     Tripets.pop_back();
   *     Tripets.push_back(t2); solve(S-1, p, Sums, Tripets);
   *   }
   *   return;
   * case 2:
   *   t1.push_back(base); t1.push_back(base+1); t1.push_back(base+1);
   *   Tripets.push_back(t1); solve(S, p, Sums, Tripets);
   *   if (S > 0) {// && base >= 1) {
   *     t2.push_back(base); t2.push_back(base); t2.push_back(base+2);
   *     Tripets.pop_back();
   *     Tripets.push_back(t2); solve(S-1, p, Sums, Tripets);
   *   }
   *   return;
   * default:
   *   return;
   * }
   */
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N, S, p;
    scanf("%d %d %d", &N, &S, &p);
    vector<int> G(N);
    for (int i = 0; i < N; i++)
      scanf("%d", &G[i]);
    ans = 0;

    vector<vector<int> > U;
    solve(S, p, G, U);
    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}
