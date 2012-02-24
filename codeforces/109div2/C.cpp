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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

#define MAX_K 13

string s;
int k;
string forbidden[MAX_K];

typedef pair<string, size_t> P;

size_t search(const string &ss, int index) {
  REP(i, k) {
    string s1 = forbidden[i];
    string s2; s2 += s1[1]; s2 += s1[0];
    //DEBUG(s1); DEBUG(s2);
    size_t loc;
    if ((loc = ss.find(s1, index)) != string::npos) return loc;
    if ((loc = ss.find(s2, index)) != string::npos) return loc;
  }
  return string::npos;
}

void dump(queue<string> q) {
  cout << "---- dump ----" << endl;
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

int bfs() {
  size_t l;
  if ((l =  search(s, 0)) == string::npos) {
    //DEBUG(ss);
    return 0;
  }

  queue<P> q;
  q.push(P(s,l));
  while (!q.empty()) {
    //DEBUG(q.size());
    //dump(q);
    P p = q.front(); q.pop();
    string ss = p.first;
    size_t loc = p.second;
    //DEBUG(ss);

    string tmp = ss; tmp.replace(loc, 1, "");
    size_t tmpl;
    if ((tmpl = search(tmp, 0)) == string::npos) {
      //DEBUG(tmp);
      return s.size() - tmp.size();
    } else {
      q.push(P(tmp, tmpl));
    }
    if (loc+1 < tmp.size()) {
      tmp = ss; tmp.replace(loc+1, 1, "");
      if ((tmpl = search(tmp, 0)) == string::npos) {
        //DEBUG(tmp);
        return s.size() - tmp.size();
      } else {
        q.push(P(tmp, tmpl));
      }
    }
  }
}

int main(int argc, char *argv[]) {

  cin >> s;

  cin >> k;
  REP(i, k) {
    cin >> forbidden[i];
    //DEBUG(forbidden[i]);
  }

  cout << bfs() << endl;

  return 0;
}
