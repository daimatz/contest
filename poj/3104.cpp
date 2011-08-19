#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
const int MAX_N = 100000;
const ll MAX_K = 1000000000;
const ll INF = 1000000000;
int n;
ll a[MAX_N], k;

bool check2(ll a, ll minute, ll j) {
  // j 回 乾燥機を使う
  ll tmp2 = a - (minute - j);
  tmp2 -= j * k;
  if (tmp2 <= 0) { // 成功
    return true;
  }
  return false;
}

bool check(ll minute) {
  ll cnt = 0;
  REP(i, n) {
    ll tmp = a[i] - minute;
    // 自然乾燥しても乾かなかった
    if (tmp > 0) { //cnt += (tmp+k-1)/k;
      bool ok = false;
      //REP(j, minute) {
      ll low = 0, high = minute;
      while (high - low > 1) {
        ll mid = (high + low) / 2;
        if (check2(a[i], minute, mid)) high = mid;
        else low = mid;
      }
      ok = high <= minute;
      if (!ok) {
        return false;
      }
      cnt += high;
    }
  }
  return cnt <= minute;
}

int main(int argc, char *argv[]) {

  while (scanf("%d", &n) != EOF) {
  //  DEBUG(n);
//    memset(a,0,sizeof(a));
  scanf("%d", &n);

  REP(i, n) {
    scanf("%lld", &a[i]);
  }

  scanf("%lld", &k);
  sort(a,a+n,greater<int>());

  if (k == 1) {
    cout << a[0] << endl;

    //return 0;
    continue;
  }

  ll low = 0, high = a[0];
  while (high - low > 1) {
    ll i = (high + low) / 2;
    if (check(i)) high = i;
    else low = i;
  }


  cout << high << endl;

  //
  }
  return 0;
}
