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



string in;

int main(int argc, char *argv[]) {
  while (cin >> in) {
    if (in == "*")
      break;
    bool flag = true;
    for (int i = 1; i < (int)in.size(); i++) {
      set<string> s;
      for (int j = 0; j < (int)in.size() - i; j++) {
        //if (i == j)
          //continue;
        string t;
        t += in[j];
        t += in[i+j];
        //DEBUG(t);
        int size = s.size();
        s.insert(t);
        if (size == (int)s.size()) {
          flag = false;
        }
      }
      if (!flag)
        break;
    }
    cout << in << " is " << (flag ? "" : "NOT ") << "surprising." << endl;
  }
  return 0;
}
