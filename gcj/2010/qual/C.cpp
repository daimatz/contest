#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

const int MAX_N = 1000;

int T, N;
long long R, k, g[MAX_N];
pair<long long, int> times[MAX_N];

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  for (int x = 0; x < T; x++) {
    scanf("%lld %lld %d", &R, &k, &N);
    for (int i = 0; i < N; i++)
      scanf("%lld", &g[i]);

    for (int z = 0; z < N; z++) {
      long long j = 0;
      int i = z;
      int si = i;
      while (j + g[i] <= k) {
        j += g[i++];
        i %= N;
        if (si == i) break;
      }
      times[z] = pair<long long, int>(j, i);
    }

    int i = 0;
    long long money = 0;
    while (R--) {
      money += times[i].first;
      i = times[i].second;
    }
    cout << "Case #" << (x+1) << ": " << money << endl;
  }
  return 0;
}
