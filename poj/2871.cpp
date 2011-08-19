/*
 last updated: 2010/06/02 02:37:59
 */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  double a, b;
  cin >> a;
  while (cin >> b) {
    if (b > (double)200)
      break;
    cout << b-a << endl;
    a = b;
  }
  cout << "End of Output" << endl;
  return 0;
}
