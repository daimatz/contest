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

map<char, char> mapping, rmapping;

int main(int argc, char *argv[]) {
  vector<string> in, out;
  in.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
  out.push_back("our language is impossible to understand");
  in.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
  out.push_back("there are twenty six factorial possibilities");
  in.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
  out.push_back("so it is okay if you want to just give up");

  for (int i = 0; i < 3; i++) {
    for (uint j = 0; j < in[i].length(); j++) {
      mapping[in[i][j]] = out[i][j];
      rmapping[out[i][j]] = in[i][j];
    }
  }
  mapping['z'] = 'q';
  rmapping['q'] = 'z';
  if (mapping.size() == 26) {
    char k, v;
    for (char c = 'a'; c <= 'z'; c++) {
      if (mapping.count(c) == 0)
        k = c;
      if (rmapping.count(c) == 0)
        v = c;
    }
    mapping[k] = v;
    rmapping[v] = k;
  }

  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    string G;
    getline(cin, G);

    printf("Case #%d: ", t);
    for (uint i = 0; i < G.size(); i++) {
      putchar(mapping[G[i]]);
    }
    puts("");
  }
  return 0;
}
