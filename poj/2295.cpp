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
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define c2d(s) ((s)-'0')
#define isd(s) ('0' <= (s) && (s) <= '9')

int pow10(int i) {
  int ret = 1;
  REP(j, i) {
    ret *= 10;
  }
  return ret;
}

int parsex(string s) {
  stack<char> stk;
  if (s[0] != '-')
    stk.push('+');
  int ret = 0;
  REP(i, s.size()) {
    if (s[i] == '-' || s[i] == '+') {
      if (!isd(s[i-1]) && s[i-1] != 'x') {
        while (!stk.empty())
          stk.pop();
        continue;
      }
      int coor = 0;
      REP(j, stk.size()-1) {
        //DEBUG(stk.top());
        coor += c2d(stk.top()) * pow10(j);
        stk.pop();
      }
      if (coor == 0)
        coor = 1;
      if (stk.top() == '-')
        coor = -coor;
      stk.pop();
      ret += coor;
    }
    //DEBUG(s[i]);
    stk.push(s[i]);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d",&T);
  while(T--){
    string s;
    cin>>s;
    string left, right;
    REP(i, s.size()) {
      if (s[i] == '=') {
        left = s.substr(0,i-1);
        right = s.substr(i+1, s.size()-1);
      }
    }
    //DEBUG(left);DEBUG(right);return 1;
    int lx, rx, l, r;
    lx = parsex(left); rx = parsex(right);
    DEBUG(lx); DEBUG(rx);
    //l = parse(left); r = parse(right);
  }
  return 0;
}
