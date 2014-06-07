#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

int N, K;
int R[MAX_N];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> R[i];
  }

  sort(R, R+N);
  double rate = 0;
  for (int i = N-K; i < N; ++i) {
    rate = (rate + R[i]) / 2.0;
  }
  printf("%lf\n", rate);
}
