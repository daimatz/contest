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
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

char buf[1024];

int f(stack<string> stk) {
  int ret = 0;
  int sgn = 1;
  int tmp = 0;
  while (!stk.empty()) {
    string s = stk.top(); stk.pop();
    if (s == "negative") {
      sgn = -1;
    } else if (s == "zero") {
      tmp = 0;
    } else if (s == "one") {
      tmp = 1;
    } else if (s == "two") {
      tmp = 2;
    } else if (s == "three") {
      tmp = 3;
    } else if (s == "four") {
      tmp = 4;
    } else if (s == "five") {
      tmp = 5;
    } else if (s == "six") {
      tmp = 6;
    } else if (s == "seven") {
      tmp = 7;
    } else if (s == "eight") {
      tmp = 8;
    } else if (s == "nine") {
      tmp = 9;
    } else if (s == "ten") {
      tmp = 10;
    } else if (s == "eleven") {
      tmp = 11;
    } else if (s == "twelve") {
      tmp = 12;
    } else if (s == "thirteen") {
      tmp = 13;
    } else if (s == "fourteen") {
      tmp = 14;
    } else if (s == "fifteen") {
      tmp = 15;
    } else if (s == "sixteen") {
      tmp = 16;
    } else if (s == "seventeen") {
      tmp = 17;
    } else if (s == "eighteen") {
      tmp = 18;
    } else if (s == "ninteen") {
      tmp = 19;
    } else if (s == "twenty") {
      tmp = 20;
    } else if (s == "thirty") {
      tmp = 30;
    } else if (s == "forty") {
      tmp = 40;
    } else if (s == "fifty") {
      tmp = 50;
    } else if (s == "sixty") {
      tmp = 60;
    } else if (s == "seventy") {
      tmp = 70;
    } else if (s == "eighty") {
      tmp = 80;
    } else if (s == "ninety") {
      tmp = 90;
    } else if (s == "hundred") {
      tmp *= 100;
    } else if (s == "thousand") {
      tmp *= 1000;
    } else if (s == "million") {
      tmp *= 1000000;
    }
    ret += tmp * sgn;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  while (cin.getline(buf, 1024)) {
    //cout << buf << endl;
    string tmp = "";
    stack<string> stk;
    int len = strlen(buf);
    REP(i, len) {
      if (buf[i] == '\n' || buf[i] == ' ') {
        stk.push(tmp);
        tmp = "";
      } else {
        tmp += buf[i];
      }
    }
    stk.push(tmp);

    cout << f(stk) << endl;
  }
  return 0;
}
