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

#define MAX_N 50
#define MAX_P 50
int step;
int N, P;
int hand[MAX_P];

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d %d", &N, &P);
    if (N == 0 && P == 0) break;
    memset(hand, 0, sizeof(hand));
    step = 0;
    while (1) {
      //DEBUG(N);
      if (P == 0) {
        P += hand[step%N];
        hand[step%N] = 0;
      } else {
        hand[step%N]++;
        P--;
        if (P == 0) {
          bool flag = true;
          REP(i, N) {
            if (i == step%N) continue;
            if (hand[i] != 0) {
              flag = false;
              break;
            }
          }
          if (flag) {
            cout << step%N << endl;
            break;
          }
        }
      }
      step++;
    }
  }
  return 0;
}
