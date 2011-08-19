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

#define INF (INT_MAX/10-1)

int n;

int main(int argc, char *argv[]) {
  scanf("%d", &n);
  REP(N, n) {
    bool eq = false;

    string s;
    cin >> s;
    DEBUG(s);

    printf("Data set %d: %s", N, (eq?"Equivalent":"Different"));
  }
  return 0;
}
