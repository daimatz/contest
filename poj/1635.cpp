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

string in;

int string_count(string s, char c) {
  int ret = 0;
  REP(i, s.length()) {
    if (s[i] == c)
      ret++;
  }
  return ret;
}


// http://www.prefield.com/algorithm/graph/isomorphism.html
typedef vector< vector<int> > Matrix;
typedef pair<int, int> VertexInfo;
#define index second
#define degree first
bool permTest(int k, const Matrix &g, const Matrix &h,
              vector<VertexInfo> &gs, vector<VertexInfo> &hs) {
  const int n = g.size();
  if (k >= n) return true;
  for (int i = k; i < n && hs[i].degree == gs[k].degree; ++i) {
    swap(hs[i], hs[k]);
    int u = gs[k].index, v = hs[k].index;
    for (int j = 0; j <= k; ++j) {
      if (g[u][gs[j].index] != h[v][hs[j].index]) goto esc;
      if (g[gs[j].index][u] != h[hs[j].index][v]) goto esc;
    }
    if (permTest(k+1, g, h, gs, hs)) return true;
  esc:swap(hs[i], hs[k]);
  }
  return false;
}
bool isomorphism(const Matrix &g, const Matrix &h) {
  const int n = g.size();
  if (h.size() != n) return false;
  vector<VertexInfo> gs(n), hs(n);
  REP(i, n) {
    gs[i].index = hs[i].index = i;
    REP(j, n) {
      gs[i].degree += g[i][j];
      hs[j].degree += h[i][j];
    }
  }
  sort(gs.begin(), gs.end()); sort(hs.begin(), hs.end());
  REP(i, n) if (gs[i].degree != hs[i].degree) return false;

  return permTest(0, g, h, gs, hs);
}



Matrix parse(string s) {
  int mx = 0, size = string_count(s, '0')+1;
  stack<int> stk;
  Matrix ret(size);
  REP(i, size) {
    vector<int> a(size);
    ret[i] = a;
  }
  stk.push(mx);
  REP(i, s.length()) {
    //DEBUG(i); DEBUG(stk.top());
    if (s[i] == '0') {
      mx++;
      int crt = stk.top();
      stk.push(mx);
      ret[crt][mx] = ret[mx][crt] = 1;
    } else {
      stk.pop();
    }
  }
  return ret;
}

void print(Matrix a) {
  REP(i, a.size()) {
    REP(j, a[i].size()) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    cin >> in;
    Matrix a = parse(in);
    cin >> in;
    Matrix b = parse(in);
    //print(a); print(b);
    if (isomorphism(a, b)) {
      cout << "same" << endl;
    } else {
      cout << "different" << endl;
    }
  }
  return 0;
}
