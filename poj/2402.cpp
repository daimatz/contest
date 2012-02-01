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

typedef long long ll;

//string table[MAX_I+1];

/**
 * string next(string s) {
 *   ll k;
 *   char buf[128];
 *   string ret;
 *   if (s.size() % 2 == 0) {
 *     int plen = s.size() / 2;
 *     k = atoll(s.substr(0, plen).c_str());
 *     k++;
 *     sprintf(buf, "%lld", k);
 *     ret = buf;
 *     int len = ret.size();
 *     if (plen != len) len--;
 *     for (int i = 0; i < len; i++) {
 *       ret += ret[len-i-1];
 *     }
 *   } else {
 *     int plen = s.size() / 2 + 1;
 *     k = atoll(s.substr(0, plen).c_str());
 *     k++;
 *     sprintf(buf, "%lld", k);
 *     ret = buf;
 *     int len = ret.size();
 *     ret = ret.substr(0, plen);
 *     if (len == plen) len--;
 *     for (int i = 0; i < len; i++) {
 *       ret += ret[len-i-1];
 *     }
 *   }
 *   return ret;
 * }
 */

int keta(ll &x) {
  int res = 0;
  ll sum = 1, now = 9;

  for (int i = 0; ; i++) {
    res++;
    if (sum + now > x) break;
    sum += now;
    if (i % 2 == 1) now *= 10;
  }
  x -= sum;
  return res;
}

int main(int argc, char *argv[]) {
  ll x;
  while (cin >> x, x) {
    int tmp = keta(x);
    ll p = 9LL * ::pow(10LL, (tmp-1)/2);
    string ans;

    for (int i = 0; i <= (tmp-1)/2; i++) {
      if (i == 0) {
        p /= 9LL;
        int div = x / p;
        ans += (char)('1'+div);
        x = x % p;
      } else {
        p /= 10LL;
        int div = x / p;
        ans += (char)('0'+div);
        x = x % p;
      }
    }
    cout << ans;
    for (int i = tmp/2-1; i>=0; i--) cout<<ans[i];
    cout << endl;
  }
  return 0;
}
