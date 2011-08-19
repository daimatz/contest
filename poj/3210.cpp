/**
 * -*- coding: utf-8-unix -*-
 * last updated: 2010/10/09 20:07:17
 */

#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    if (n % 2 == 0) cout << "No Solution!" << endl;
    else cout << n-1 << endl;
  }
  return 0;
}
