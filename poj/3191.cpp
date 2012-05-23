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

#define MAX_N 2000000000

ll pow(ll n, ll k) {
  if (k == 0) return 1;
  if (k % 2 == 0) {
    ll p = pow(n, k/2);
    return p*p;
  }
  return n*pow(n, k-1);
}

// max of m-th group
inline ll x(ll m) {
  return (pow(4,m)-1)/3;
}

// min of m-th group
inline ll y(ll m) {
  return -2*x(m);
}

inline ll z(ll n) {
  ll m;
  if (n > 0) {
    for (m = 0; x(m) < n; m++)
      ;
    // m-th group
    return m;
  } else {
    for (m = 0; y(m) > n; m++)
      ;
    return m;
  }
}

inline ll w(ll n) {
  if (n == 0) return 0;
  ll m = z(n);
  if (n > 0) return 2*m-1;
  else return 2*m;
}

string ans(ll n) {
//  DEBUG(n);
  if (n == 0) return "";
  if (n > 0) {
    ll m;
    string ret = "1";
    m = z(n);
    ll o = w(n);
    // m-th group
    ll nn = n-pow(2,2*m-2);
    ll no = w(nn);
    REP(i, o-no-1) ret += "0";
//    DEBUG(m);
    return ret+ans(nn);
  } else {
    ll m;
    string ret = "1";
    m = z(n);
    ll o = w(n);
    // m-th group
    ll nn = n+pow(2,2*m-1);
    ll no = w(nn);
    REP(i, o-no-1) ret += "0";
    m = z(n);
//    DEBUG(m);
    return ret+ans(nn);
  }
}

ll val(string s) {
  ll ret = 0;
  REP(i, s.size()) {
    ret += (s[s.size()-i-1]-'0')*pow(-2,i);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  while (cin >> n) {
    string a;
    if (n == 0) a = "0";
    else a = ans(n);
    cout << a << endl;
    DEBUG(val(a));
  }

  return 0;
}
