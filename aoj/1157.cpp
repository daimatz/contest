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
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8


typedef complex<double> P;
typedef pair<P,P> Line;

#define MAX_N 50
int N;
int sx, sy, ex, ey;
P S, E;

struct Shape {
  P p[4];
  int h;
};
Shape shapes[MAX_N];

double d(Line line, P p) {
  int a, b;
  int dx = line.first.real() - line.second.real();
  int dy = line.first.imag() - line.second.imag();
  a = -dy, b = dx;
  //DEBUG(a); DEBUG(b);
  int c = -a * line.first.real() - b * line.first.imag();
  //DEBUG(c);
  return ((double) abs(a*p.real()+b*p.imag()+c)) / sqrt(a*a+b*b);
}

double d(P p1, P p2) {
  int dx = p1.real() - p2.real(), dy = p1.imag() - p2.imag();
  return sqrt(dx*dx+dy*dy);
}

double d(Line l1, Line l2) {
  return min(min(d(l1,l2.first), d(l1,l2.second)), min(d(l2,l1.first),d(l2,l1.second)));
}

bool inter(Line p1, Line p2) {
  double x1 = p1.first.real(), y1 = p1.first.imag(), x2 = p1.second.real(), y2 = p1.second.imag(),
    x3 = p2.first.real(), y3 = p2.first.imag(), x4 = p2.second.real(), y4 = p2.second.imag();
  double tc = (x1-x2)*(y3-y1)-(y1-y2)*(x3-x1), td = (x1-x2)*(y4-y1)-(y1-y2)*(x4-x1);
  double ta = (x3-x4)*(y1-y3)-(y3-y4)*(x1-x3), tb = (x3-x4)*(y2-y3)-(y3-y4)*(x2-x3);
  return ((ta*tb < 0 || abs(ta*tb) < EPS) && (abs(tc*td) < EPS || tc*td < 0));
}

int main(int argc, char *argv[]) {
  while (1) {
    scanf("%d", &N);
    if (N == 0) break;

    double ans = INF;

    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    P SE[2] = {P(sx,sy), P(ex,ey)};
    REP(i, N) {
      int minx, miny, maxx, maxy, h;
      scanf("%d %d %d %d %d", &minx, &miny, &maxx, &maxy, &h);
      Shape s;
      s.p[0] = P(minx, miny);
      s.p[1] = P(maxx, miny);
      s.p[2] = P(maxx, maxy);
      s.p[3] = P(minx, maxy);
      s.h = h;
      shapes[i] = s;
      REP(i, 2) {
        // 障害物がスタートゴールを完全に覆っている
        if (minx < SE[i].real() && SE[i].real() < maxx
            && miny < SE[i].imag() && SE[i].imag() < maxy)
          ans = 0;
      }
      // 障害物がスタートゴール間を遮っている
      REP(i, 4) {
        Line l(s.p[i], s.p[(i+1)%4]);
        if (inter(l, Line(SE[0],SE[1])))
          ans = 0;
      }
    }

    //DEBUG(d(Line(P(-40,-40),P(100,30)),P(30,-30))); break;

    // sed[0], sed[1] はそれぞれスタート・ゴールから一番近い障害物への最大半径
    double sed[2] = {INF,INF};
    REP(i, N) {
      // 各長方形
      Shape s = shapes[i];
      // 各辺に対して、その辺とスタート・ゴールの距離
      REP(j, 4) {
        /**
         * REP(k, 2) {
         *   P p1 = s.p[j], p2 = s.p[(j+1)%4];
         *   double tmp = INF;
         *   bool t1 = (p1.real() < SE[k].real() && SE[k].real() < p2.real())
         *     || (p2.real() < SE[k].real() && SE[k].real() < p1.real());
         *   bool t2 = (p1.imag() < SE[k].imag() && SE[k].imag() < p2.imag())
         *     || (p2.imag() < SE[k].imag() && SE[k].imag() < p1.imag());
         *   if (t1)
         *     tmp = abs(SE[k].imag() - p1.imag());
         *   else if (t2)
         *     tmp = abs(SE[k].real() - p1.real());
         *   else
         *     tmp = min(d(p1,SE[k]),d(p2,SE[k]));
         *   //DEBUG(tmp);
         *   sed[k] = min( (s.h >= tmp) ? s.h : (tmp*tmp+s.h*s.h) / (2*s.h), sed[k]);
         * }
         */
        double tmp = d(Line(s.p[j], s.p[(j+1)%4]), Line(SE[0], SE[1]));
        /**
         * REP(k,2)
         *   sed[k] = min( (s.h >= tmp) ? s.h : (tmp*tmp+s.h*s.h) / (2*s.h), sed[k]);
         */
        DEBUG(tmp); DEBUG(s.h);
        if (s.h > tmp) ans = min(ans,tmp);
        else ans = min(ans, (tmp*tmp+s.h*s.h)/(2*s.h));
      }
    }
    //DEBUG(sed[0]); DEBUG(sed[1]);// break;

    /**
     * // 各障害物に対して、各頂点とスタートゴール間の距離
     * Line line(SE[0], SE[1]);
     * // スタートゴールに直交するベクトル
     * int v[] = {SE[0].imag()-SE[1].imag(),-(SE[0].real()-SE[1].real())};
     * // スタート or ゴールを通ってスタートゴールに直交する直線の y 切片
     * double cs = ((double)(v[0]*SE[0].imag() - v[1]*SE[0].real())) / v[0];
     * double ce = ((double)(v[0]*SE[1].imag() - v[1]*SE[1].real())) / v[0];
     * //DEBUG(cs); DEBUG(ce);
     * double mind = INF;
     * REP(i, N) {
     *   Shape s = shapes[i];
     *   REP(j, 4) {
     *     P p = s.p[j];
     *     // p を通ってスタートゴールに直交する直線の y 切片
     *     double c = ((double)(v[0]*p.imag() - v[1]*p.real())) / v[0];
     *     //DEBUG(c);
     *     // p を通ってスタートゴールに直交する直線とスタートゴールの線分が交差していない
     *     // ならば、その距離は考えなくてよい
     *     //double tmp = ((cs < c && c < ce) || (ce < c && c < cs)) ? INF : d(line, p);
     *     double tmp = d(line, p);
     *     mind = min( (s.h >= tmp) ? s.h : (tmp*tmp+s.h*s.h) / (2*s.h), mind);
     *   }
     * }
     * //DEBUG(mind); break;
     *
     * ans = min(min(min(sed[0],sed[1]), mind), ans);
     */

    printf("%.4f\n", ans);

  }
  return 0;
}
