/*
 last updated: 2010/06/22 23:31:12
 */
#include <iostream>
#include <list>
using namespace std;

class ll {
public:
  int l;
  int w;
  ll(int l, int w) { this->l = l; this->w = w;}
  bool operator<(ll t);
  bool operator>(ll t);
  bool operator==(ll t);
  bool operator<=(ll t);
  bool operator>=(ll t);
};

bool ll::operator<(ll t) {
  return (this->l < t.l || (this->l == t.l && this->w < t.w));
}

bool ll::operator>(ll t) {
  return t < *this;
}

bool ll::operator==(ll t) {
  return (this->l == t.l && this->w == t.w);
}

bool ll::operator<=(ll t) {
  return (this->l <= t.l && this->w <= t.w);
}

bool ll::operator>=(ll t) {
  return t <= *this;
}

void printlist(list<ll> lst) {
  list<ll>::iterator it;
  for (it = lst.begin(); it != lst.end(); it++) {
    cout << it->l << " " << it->w << endl;
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int c;
    cin >> c;
    list<ll> lst;
    while (c--) {
      int p, q;
      cin >> p >> q;
      ll k(p, q);
      lst.push_back(k);
    }
    lst.sort();
    list<ll>::iterator it, jt, kt;
    for (it = lst.begin(); it != lst.end(); it++) {
      jt = it; jt++; if (jt == lst.end()) break;
      if (!(*it <= *jt)) {
        for (kt = jt; kt != lst.end(); kt++) {
          if (*it <= *kt) {
            lst.insert(jt, *kt);
            kt = lst.erase(kt);
            kt--;
          }
        }
        jt--;
      }
      it = jt;
    }
    /**
     * printlist(lst);
     * cout << "---" << endl;
     */
    int ans = 1;
    for (it = lst.begin(); it != lst.end(); it++) {
      jt = it; jt++; if (jt == lst.end()) break;
      if (!(*it <= *jt))
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
