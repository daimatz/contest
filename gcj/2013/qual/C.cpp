#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;

bool is_par(ll n) {
  char s[60];
  snprintf(s, 60, "%lld", n);
  string str(s);
  int len = str.size();
  for (int i = 0; i < len/2; ++i) {
    if (str[i] != str[len-i-1]) return false;
  }
  return true;
}

vector<ll> squares;

void pre() {
  for (ll i = 1; i <= 10000000000; ++i) {
    ll k = i*i;
    if (is_par(i) && is_par(k)) {
      cout << i << " " << k << endl;
      squares.push_back(k);
    }
  }
}

ll solve(ll a, ll b) {
  int cnt = 0;
  for (int i = 0; i < squares.size(); ++i) {
    if (a <= squares[i] && squares[i] <= b) {
      ++cnt;
    }
  }
  return cnt;
}

int main() {
  pre();
  int T;
  cin >> T;
  ll a, b;
  for (int i = 1; i <= T; ++i) {
    cin >> a >> b;
    cout << "Case #" << i << ": " << solve(a, b) << endl;
  }
}
