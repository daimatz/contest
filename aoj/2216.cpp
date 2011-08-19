#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

void solve(int A, int B) {
  int coin[3];
  long turi = B - A;

  for (int i = 0; i < 3; i++)
    coin[i] = 0;

  coin[2] = turi / 1000;
  turi %= 1000;

  coin[1] = turi / 500;
  turi %= 500;

  coin[0] = turi / 100;

  cout << coin[0] << " " << coin[1] << " " << coin[2] << endl;
}

int main(int argc, char *argv[]) {
  while (true) {
    long A, B;
    scanf("%d %d", &A, &B);
    if (A ==0 && B == 0)
      break;
    solve(A, B);
  }
  return 0;
}
