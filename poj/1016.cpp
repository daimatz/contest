/**
 * -*- coding: utf-8-unix -*-
 * last updated: 2010/11/22 02:13:59
 */

#include <iostream>
#include <cstdio>
#include <list>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

string in;

string inventory(string s) {
  string ret = "";
  bool flag = false;
  for (char i = '0'; i <= '9'; i++) {
    int c = 0;
    for (unsigned int j = 0; j < s.length(); j++) {
      if (flag == false && s[j] == i)
        flag = true;
      if (s[j] == i) {
        c++;
      }
    }
    if (c != 0 && flag == true) {
      char temp[255];
      snprintf(temp, 255, "%d%c", c, i);
      string tt(temp);
      ret += tt;
    }
  }
  return ret;
}

void solve() {
  string str = in, str2 = "-1";
  list<string> ls;
  for (int i = 0; ; i++) {
    str2 = inventory(str);
    ls.push_back(str2);
    if (ls.back() == inventory(ls.back())) {
      if (i == 0) {
        cout << in << " is self-inventorying" << endl;
      } else {
        cout << in << " is self-inventorying after " << i+1 << " steps" << endl;
      }
      return;
    }
    if (ls.size() != 1) {
      int k = 0;
      for (list<string>::iterator it = ls.begin();
           it != ls.end();
           it++) {
        k++;
        if (*it == inventory(ls.back())) {
          cout << in << " enters an inventory loop of length " << ls.size() - k + 1 << endl;
          return;
        }
      }
    }
//    DEBUG(str); DEBUG(str2);
    str = str2;
    if (i == 15) {
      cout << in << " can not be classified after 15 iterations" << endl;
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  while (1) {
    cin >> in;
    if (in == "-1")
      break;
    solve();
  }
  return 0;
}
