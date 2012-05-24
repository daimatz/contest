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

typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(const mat &a, const mat &b) {
  mat ret(a.size(), vec(b[0].size()));
  REP(i, ret.size()) REP(j, ret[i].size()) REP(k, a[i].size())
    ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % 10000;
  return ret;
}

mat identity(int n) {
  mat A(n, vec(n));
  for (int i = 0; i < n; ++i) A[i][i] = 1;
  return A;
}

mat pow(const mat &A, ll e) {
  return e == 0 ? identity(A.size())  :
    e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  mat a(2, vec(2));
  a[0][0] = a[0][1] = a[1][0] = 1; a[1][1] = 0;

  ll n;
  while (1) {
    cin >> n;
    if (n == -1) break;
    mat m = pow(a, n);
    cout << m[1][0] << endl;
  }

  return 0;
}
