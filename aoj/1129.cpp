#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int n, r;

int main(int argc, char *argv[]) {

  while (true) {

    scanf("%d %d", &n, &r);
    if (n == 0 && r == 0)
      break;

    int a[n];

    for (int i = 0; i < n; i++)
      a[i] = n-i;;

    for (int i = 0; i < r; i++) {
      int p, c;
      scanf("%d %d", &p, &c);

      int b[n];

      for (int j = 0; j < n; j++) {
        if (p-1 <= j && j < p-1+c) {
          b[j-(p-1)] = a[j];
        } else if (j < p-1) {
          b[j+c] = a[j];
        } else {
          b[j] = a[j];
        }
      }

      for (int j = 0; j < n; j++) {
        a[j] = b[j]; // memcpy...
        //DEBUG(a[j]);
      }

    }

    cout << a[0] << endl;

  }

  return 0;
}
