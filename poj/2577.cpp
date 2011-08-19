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

int mm[10000][3], reg[10], ptr = 0, cnt = 0;

void f0(int d, int s) {
  if (reg[s] != 0)
    ptr = reg[d];
  else
    ptr++;
}

void f2(int d, int n) {
  reg[d] = n;
  ptr++;
}

void f3(int d, int n) {
  reg[d] = (reg[d]+n)%1000;
  ptr++;
}

void f4(int d, int n) {
  reg[d] = (reg[d] * n)%1000;
  ptr++;
}

void f5(int d, int s) {
  reg[d] = reg[s];
  ptr++;
}

void f6(int d, int s) {
  reg[d] = (reg[d] +reg[s])%1000;
  ptr++;
}

void f7(int d, int s) {
  reg[d] = (reg[d]*reg[s])%1000;
  ptr++;
}

void f8(int d, int a) {
  reg[d] = mm[reg[a]][0]*100+mm[reg[a]][1]*10+mm[reg[a]][2];
  ptr++;
}

void f9(int s, int a) {
  //reg[reg[a]] = reg[s];
  mm[reg[a]][0] = reg[s]/100;
  mm[reg[a]][1] = (reg[s]/10) % 10;
  mm[reg[a]][2] = (reg[s]) % 10;
  ptr++;
}

void solve() {
  while (1) {
    cnt++;
    //DEBUG(ptr);
    switch (mm[ptr][0]) {
    case 1: return;
    case 2: f2(mm[ptr][1], mm[ptr][2]); break;
    case 3: f3(mm[ptr][1], mm[ptr][2]); break;
    case 4: f4(mm[ptr][1], mm[ptr][2]); break;
    case 5: f5(mm[ptr][1], mm[ptr][2]); break;
    case 6: f6(mm[ptr][1], mm[ptr][2]); break;
    case 7: f7(mm[ptr][1], mm[ptr][2]); break;
    case 8: f8(mm[ptr][1], mm[ptr][2]); break;
    case 9: f9(mm[ptr][1], mm[ptr][2]); break;
    case 0: f0(mm[ptr][1], mm[ptr][2]); break;
    }
  }
}

int main(int argc, char *argv[]) {
  int step = 0;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < 3; i++) {
      mm[step][2-i] = n % 10;
      n /= 10;
    }
    step++;
  }

  /**
   * REP(i, step) {
   *   REP(j, 3) {
   *     cout << mm[i][j];
   *   }
   *   cout << endl;
   * }
   * return 0;
   */

  solve();

  cout << cnt << endl;
  return 0;
}
