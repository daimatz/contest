/*
 last updated: 2010/08/24 02:32:26
 */
#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int max2(int x, int y) {
  return (x > y ? x : y);
}

int max(int a, int b, int c, int d, int e, int f) {
  return max2(max2(max2(a, b), max2(c, d)), max2(e, f));
}

int min(int a, int b, int c, int d, int e, int f) {
  return -max(-a, -b, -c, -d, -e, -f);
}

int main(int argc, char *argv[]) {
  int a, b, c, d, e, f;
  double s;
  while (1) {
    cin >> a >> b >> c >> d >> e >> f;
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
      break;
    s = (a + b + c + d + e + f - max(a,b,c,d,e,f) - min(a,b,c,d,e,f))/4.0;
    cout << s << endl;
  }
  return 0;
}
