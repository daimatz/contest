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

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  scanf("%d\n", &N);
  int sum = 0;
  map<char, int> mp;
  mp.insert({'A',4});
  mp.insert({'B',3});
  mp.insert({'C',2});
  mp.insert({'D',1});
  mp.insert({'F',0});
  REP(i, N) sum += mp[getchar()];
  DEBUG(sum);
  printf("%.9f\n", (double)sum / N);

  return 0;
}
