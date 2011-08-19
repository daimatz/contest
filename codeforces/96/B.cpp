#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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

vector<long long> vec;

long long f(int n) {
  REP(i, vec.size()) {
    if (vec[i] >= n)
      return vec[i];
  }
}

int main(int argc, char *argv[]) {
  string t = "47";

  set<string> st;
  while (t.size() <= 8) {
    char s[11];
    strcpy(s,t.c_str());
    do {
      st.insert(string(s));
    } while (next_permutation(s, s+t.size()));

    t = "4"+t+"7";
  }
  st.insert(string(t));

  FOR(it, st) {
    vec.push_back(atoll(it->c_str()));
  }
  sort(vec.begin(), vec.end());

  /**
   * REP(j, size) {
   *   cout << m[j] << endl;
   * }
   */
  //while (cin >> in)
  //DEBUG(*(vec.end()-1));
  int in;
  while (cin>>in)
    cout << f(in) << endl;

  return 0;
}
