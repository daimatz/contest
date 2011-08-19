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

static int a[128 * 1024];

bool check(int n, int k, int m)
{
  ll needed = 0;
  for (int i = 0; i < n; ++i) {
    int rest = a[i] - m;
    if (rest < 0) {
      rest = 0;
    }
    needed += (rest + k - 1) / k;
  }
  return needed <= m;
}

int main() {
  int n;
  //while (scanf("%d", &n) != EOF) {
  while (cin >> n) {
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int k;
  scanf("%d", &k);
  --k;

  if (k == 0) {
    cout << *max_element(a, a + n) << endl;
    //return 0;
    continue;
  }

  int L = 0;
  int R = 1LL << 30;
  while (L + 1 < R){
    int M = (L + R) / 2;
    if (check(n, k, M)){
      R = M;
    } else {
      L = M;
    }
  }

  cout << L + 1 << endl;
  }
}
