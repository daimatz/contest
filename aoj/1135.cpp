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

#define K_MAX 100
int m, n, year;
ll money;

const int INF = 100000;

int main(int argc, char *argv[]) {
  scanf("%d", &m);
  while (m--) {
    ll money;
    scanf("%lld", &money);
    scanf("%d", &year);
    scanf("%d", &n);

    ll max = money;
    for (int i = 0; i < n; i++) {
      ll mt = money;
      int t, c;
      double d;
      scanf("%d %lf %d", &t, &d, &c);
      if (t == 0) { // tanri
        ll rk = 0;
        for (int j = 0; j < year; j++) {
          ll risi = (ll)(mt*d);
          rk += risi;
          mt -= c;
        }
        mt += rk;
      } else { // fukuri
        for (int j = 0; j < year; j++)
          mt += ((ll)(mt*d))-c;
      }
      if (mt > max)
        max = mt;
    }

    cout << max << endl;

  }
  return 0;
}
