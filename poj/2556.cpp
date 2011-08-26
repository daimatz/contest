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

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main(int argc, char *argv[]) {
  string in;
  while (cin >> in) {
    cout << "300 420 moveto" << endl;
    cout << "310 420 lineto" << endl;

    int x = 310, y = 420;
    int d = 1;

    REP(i, in.size()) {
      if (in[i] == 'A') d = (d+1)%4;
      if (in[i] == 'V') d = (d+3)%4;
      x += dx[d] * 10;
      y += dy[d] * 10;
      cout << x << " " << y << " lineto" << endl;
    }
    cout << "stroke" << endl;
    cout << "showpage" << endl;
  }
  return 0;
}
