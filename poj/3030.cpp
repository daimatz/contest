#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;



int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    long r, e, c;
    cin >> r >> e >> c;
    if (r < e-c)
      cout << "advertise" << endl;
    else if (r == e-c)
      cout << "does not matter" << endl;
    else // if (r > e-c)
      cout << "do not advertise" << endl;
  }
  return 0;
}
