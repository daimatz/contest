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

map<string, string> dic;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  char from[100], to[100];
  char c;
  while ((c = getchar()) != '\n') {
    to[0] = c;
    scanf("%s %s", to+1, from);
    getchar();
    dic.insert(make_pair(from, to));
  }
  while (scanf("%s\n", from) != EOF) {
    if (dic.count(from) < 1) puts("eh");
    else printf("%s\n", dic[from].c_str());
  }

  return 0;
}
