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

#define MAX_L 1000000
#define MAX_P 1000000
#define MAX_N 10000

int main(int argc, char *argv[]) {
  int N;
  ll A[MAX_N], B[MAX_N], L, P;
  scanf("%d", &N);
  priority_queue<int> q;
  REP(i, N) {
    scanf("%lld %lld", &A[i], &B[i]);
  }
  scanf("%lld %lld", &L, &P);
  ll cnt = 0;
  while (1) {
    L -= P;
    //DEBUG(L);
    if (L <= 0)
      break;
    P = 0;
    REP(i, N) {
      if (A[i] <= L)
        q.push(B[i]);
    }
    if (q.empty()) {
      cnt = -1;
      break;
    }
    P += q.top();
    q.pop();
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
