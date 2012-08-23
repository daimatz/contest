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
#define DEBUG(x) cerr<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

char t[255];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> v;
  v.push_back("`1234567890-=");
  v.push_back("QWERTYUIOP[]\\");
  v.push_back("ASDFGHJKL;'");
  v.push_back("ZXCVBNM,./");
  REP(i, v.size()) REP(j, v[i].size()-1) t[v[i][j+1]] = v[i][j];
  t[' '] = ' ';

  string in;
  while (1) {
    getline(cin, in);
    if (cin.eof()) break;
    if (!in.empty()) {
      REP(i, in.size()) cout << t[in[i]];
      cout << endl;
    }
  }

  return 0;
}
