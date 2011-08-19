#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  while (N--) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      if (x % 2 == 0) {
        cout << 2*x << endl;
      } else {
        cout << 2*x-1 << endl;
      }
    } else if (x == y+2) {
      if (x % 2 == 0) {
        cout << 2*x-2 << endl;
      } else {
        cout << 2*x-3 << endl;
      }
    } else {
      cout << "No Number" << endl;
    }
  }
  return 0;
}
