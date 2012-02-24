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

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_N 1000

int n;
int score[MAX_N];

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &score[i]);
  }

  int h, l;
  h = l = score[0];
  int count = 0;

  REP(i, n) {
    if (h < score[i]) {
      count++;
      h = score[i];
    }
    if (l > score[i]) {
      count++;
      l = score[i];
    }
  }

  cout << count << endl;

  return 0;
}
