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

struct P {
  int a, b;
  P() { a=b=0; }
  P(int _a, int _b) {a=_a,b=_b;}
  void print() { cout << a << " " << b << endl; }
};

int n;
P v[MAX_N];

bool f(P p, P q) {
  return p.b > q.b;
}

bool g(P p, P q) {
  return p.a > q.a;
}

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[i] = P(a, b);
  }

  sort(v, v+n, f);

  //REP(i, n) v[i].print();

  long long score = 0;
  int i = 0;
  int rest = 1;
  while (i < n) {
    if (v[i].b > 0) {
      rest = rest + v[i].b - 1;
      score += v[i].a;
      i++;
    } else {
      break;
    }
  }

  sort(v+i, v+n, g);

  //REP(i, n) v[i].print();

  while (i < n && rest--) {
    score += v[i].a;
    i++;
  }

  cout <<  score << endl;

  return 0;
}
