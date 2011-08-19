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
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1e-8
typedef complex<double> P;
typedef pair<P, P> Line;

struct Shape {
  char n; // name. A, B, ...
  vector<Line> l; // points
  bool operator<(const Shape &a) const {
    return (n < a.n);
  }
};

vector<Shape> shapes;

bool inter(Line p1, Line p2) {
  double x1 = p1.first.real(), y1 = p1.first.imag(), x2 = p1.second.real(), y2 = p1.second.imag(),
    x3 = p2.first.real(), y3 = p2.first.imag(), x4 = p2.second.real(), y4 = p2.second.imag();
  double tc = (x1-x2)*(y3-y1)-(y1-y2)*(x3-x1), td = (x1-x2)*(y4-y1)-(y1-y2)*(x4-x1);
  double ta = (x3-x4)*(y1-y3)-(y3-y4)*(x1-x3), tb = (x3-x4)*(y2-y3)-(y3-y4)*(x2-x3);
  return ((ta*tb < 0 || abs(ta*tb) < EPS) && (abs(tc*td) < EPS || tc*td < 0));
}

void solve() {
  /**
   * FOR(i, shapes) {
   *   DEBUG(i->n);
   *   FOR(j, i->l) {
   *     DEBUG(j->first);
   *     DEBUG(j->second);
   *   }
   * }
   */
  FOR(i,shapes) {
    vector<char> ins;
    vector<Line> lines1 = i->l;
    FOR(j, shapes) {
      if (i == j)
        continue;
      // i と j が交差しているか？
      vector<Line> lines2 = j->l;
      FOR(k, lines1) {
        FOR(l, lines2) {
          /**
           * if (i->n == 'B' && j->n == 'S') {
           *   DEBUG(k->first); DEBUG(k->second); DEBUG(l->first); DEBUG(l->second);
           * }
           */
          if (inter(*k, *l)) {
            ins.push_back(j->n);
            goto brk;
          }
        }
      }
    brk: ;
    }
    if (ins.empty())
      cout << i->n << " has no intersections" << endl;
    else {
      string s;
      s = i->n;
      s += " intersects with ";
      FOR(j, ins) {
        if (j == ins.begin()) {
          s += *j;
        } else if (j+1 == ins.end()) {
          if (ins.size() != 2)
            s += ",";
          s += " and ";
          s += *j;
        } else {
          s += ", ";
          s += *j;
        }
      }
      cout << s << endl;
    }
  }
  puts("");
}

int main(int argc, char *argv[]) {
  /**
     square: 0
     rectangle: 1
     line: 2
     triangle: 3
     polygon: 4
  */
  while (1) {
    shapes.clear();
    while (1) {
      char c;
      scanf(" %c", &c);
      if (c == '-')
        break;
      else if (c == '.')
        return 0;
      string s;
      Shape tmp;
      tmp.n = c;
      cin >> s;
      //DEBUG(s);
      int x,y;
      if (s == "square") {
        int x1, x2, y1, y2;
        scanf(" (%d,%d) (%d,%d)", &x1, &y1, &x2, &y2);
        P v1(x2-x1,y2-y1);
        P v2;
        v2 = v1*P(1.0/2.0,1.0/2.0);
        P p0(x1,y1); P p1(p0+v2); P p2(x2, y2); P p3(p2-v2);
        tmp.l.push_back(Line(p0,p1));
        tmp.l.push_back(Line(p1,p2));
        tmp.l.push_back(Line(p2,p3));
        tmp.l.push_back(Line(p3,p0));
      } else if (s == "rectangle") {
        int x1,x2,x3,y1,y2,y3;
        scanf(" (%d,%d) (%d,%d) (%d,%d)", &x1, &y1, &x2, &y2, &x3, &y3);
        int x4 = x1+x3-x2, y4 = y1+y3-y2;
        tmp.l.push_back(Line(P(x1,y1),P(x2,y2)));
        tmp.l.push_back(Line(P(x2,y2),P(x3,y3)));
        tmp.l.push_back(Line(P(x3,y3),P(x4,y4)));
        tmp.l.push_back(Line(P(x4,y4),P(x1,y1)));
      } else if (s == "line") {
        int x1,x2,y1,y2;
        scanf(" (%d,%d) (%d,%d)", &x1, &y1, &x2, &y2);
        tmp.l.push_back(Line(P(x1,y1),P(x2,y2)));
      } else if (s == "triangle") {
        vector<P> ps;
        REP(i,3) {
          scanf(" (%d,%d)", &x, &y);
          ps.push_back(P(x,y));
        }
        FOR(i,ps) {
          vector<P>::iterator j = (i+1 == ps.end()) ? ps.begin() : i+1;
          tmp.l.push_back(Line(*i,*j));
        }
      } else if (s == "polygon") {
        int n;
        scanf("%d", &n);
        vector<P> ps;
        REP(i,n ) {
          scanf(" (%d,%d)", &x, &y);
          ps.push_back(P(x,y));
        }
        FOR(i,ps) {
          vector<P>::iterator j = (i+1 == ps.end()) ? ps.begin() : i+1;
          tmp.l.push_back(Line(*i,*j));
        }
      }
      shapes.push_back(tmp);
    }
    sort(shapes.begin(), shapes.end());
    solve();
  }
  return 0;
}
