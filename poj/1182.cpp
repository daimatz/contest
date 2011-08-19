#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(typeof(n) i = 0; i < (n); i++)
using namespace std;

#define MAX_N 50000
#define MAX_K 100000

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d %d", &N, &K);
  int ans = 0;
  REP(i, K) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > N || y > N) {
      ans++;
      continue;
    }
  }
  printf("%d", ans);
  return 0;
}
