/*
 last updated: 2010/07/31 05:10:48
 */
#include <iostream>
#include <iomanip>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  double k = 0;
  cout << "n e" << endl;
  cout << "- -----------" << endl;
  int j = 1;
  ios_base::fmtflags flag;
  flag = cout.setf(ios_base::fixed);

  for (int i = 0; i < 10; i++) {
    j = (i == 0 ? 1 : j * i);
    k += 1.0 / (double) j;
    cout << i << " " << setprecision(9) << k << endl;
  }
  return 0;
}
