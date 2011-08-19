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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;

#define INF (INT_MAX/10-1)

#define MAX_N 10
int T, N;

string s[MAX_N];
int mp[MAX_N][MAX_N];
int ln[MAX_N];

int f(string s1, string s2) {
  int len = min(s1.size(), s2.size());
  int ret = 0;
  for (int i = 0; i <= len; i++) {
    if (s2.substr(0, i) == s1.substr(s1.size()-i, i))
      ret = i;
  }
  return ret;
}

int total(int k[]) {
  int ret = ln[k[0]];
  //int ret = s[k[0]].size();
  REP(i, N-1) {
    ret += ln[k[i+1]] - mp[k[i]][k[i+1]];
    //ret += s[k[i+1]].size() - f(s[k[i]], s[k[i+1]]);
    //キャッシュしないとTLE
  }
  /** DEBUG(ret); */
  return ret;
}

int main(int argc, char *argv[]) {
  //DEBUG(f("AAAA", "AAA"));return 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    REP(i, N) {
      cin >> s[i];
    }
    REP(i, N) {
      REP(j, i) {
        mp[i][j] = f(s[i], s[j]);
        mp[j][i] = f(s[j], s[i]);
      }
      ln[i] = s[i].size();
    }
    /**
     * REP(i, N) {
     *   REP(j, N) {
     *     DEBUG(mp[i][j]);
     *   }
     * }
     */

    int k[N];
    REP(i, N) {
      k[i] = i;
    }

    int min = INF;
    do {
      int tmp = total(k);
      if (min > tmp)
        min = tmp;
    } while (next_permutation(k, k+N));
    cout << min << endl;
    /**
     * int l[] = {3,1,4,2,0};
     * DEBUG(total(l));
     */
  }
  return 0;
}
