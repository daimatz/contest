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

typedef vector<int> vec;
typedef vector<vec> mat;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

const int M = 10007;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vec(B[0].size()));
  REP(i, A.size()) REP(k, B.size()) REP(j, B[0].size())
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
  return C;
}

mat pow(mat A, ll n) {
  mat B(A.size(), vec(A.size()));
  REP(i, A.size()) B[i][i] = 1;
  while (n > 0) {
    if (n & 1) B = mul(B,A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

ll N;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    mat A(3, vec(3));
    A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
    A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
    A = pow(A, N);
    cout << A[0][0] << endl;
  }

  return 0;
}
