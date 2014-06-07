#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef pair<double, double> P;

int main() {
  double xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  xb -= xa;
  yb -= ya;
  xc -= xa;
  yc -= ya;
  printf("%lf\n", 0.5 * fabs(xb * yc - yb * xc));
}
