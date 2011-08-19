#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

#include <cstdio>

using namespace std;

int T, N, K;

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d %d", &N, &K);
    int mask = (1<<N)-1;
    printf("Case #%d: %s\n", t, (mask&K)==mask?"ON":"OFF");
  }
  return 0;
}
