#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
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
#define DEBUG(x) cerr<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS (1.0e-8)

vector<string> ss = {"a","b","c","d","e","f","g","h","i","j","k"};
vector<string> T = {"(F->F)","(F->T)","(T->T)","(T*T)","(T+T)","(T+F)","(F+T)","-F"};
vector<string> F = {"(T->F)","(F*F)","(T*F)","(F*T)","(F+F)","-T"};

string in;
string ls, rs;
vector<string> alphabet;

bool replace(string& str, const string& from, const string& to) {
  string::size_type pos = 0;
  bool ret = false;
  while(pos = str.find(from, pos), pos != string::npos) {
    str.replace(pos, from.length(), to);
    pos += to.length();
    ret = true;
  }
  return ret;
}

string val(string s, int assign) {
  string::size_type idx;
  REP(i, alphabet.size()) {
    while((idx = s.find(alphabet[i])) != string::npos) {
      if (idx < s.size()) s[idx] = (assign & (1<<i)) ? 'T' : 'F';
    }
  }
  int flag = true;
  while (flag) {
    flag = false;
    REP(i, T.size()) flag |= replace(s, T[i], "T");
    REP(i, F.size()) flag |= replace(s, F[i], "F");
  }
  return s;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (cin>>in) {
    if (in == "#") break;

    alphabet.clear();
    string::size_type eq = in.find("=");
    if (eq == string::npos) break;
    ls = in.substr(0,eq); rs = in.substr(eq+1);
    REP(i, ss.size()) {
      if (in.find(ss[i]) != string::npos) alphabet.push_back(ss[i]);
    }

    int flag = true;
    //DEBUG(ls);
    REP(i, 1<<alphabet.size()) {
      if (val(ls, i) != val(rs, i)) {
        flag = false;
        break;
      }
    }
    cout << (flag?"YES":"NO") << endl;
  }

  return 0;
}
