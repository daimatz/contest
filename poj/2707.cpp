/*
 last updated: 2010/07/31 04:07:44
 */
#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int max(int a, int b) {
  return (a > b) ? a : b;
}
int min(int a, int b) {
  return (a < b) ? a : b;
}

int main(int argc, char *argv[]) {
  while (true) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
      break;
    int p1 = c * 100 / a, p2 = d * 100 / b;
    int p3 = d * 100 / a, p4 = c * 100 / b;
    cout << min(max(min(p1, p2), min(p3, p4)), 100) << "%" << endl;
  }
  return 0;
}
