#include <iostream>
#include <string>
#include <sstream>
#define MAX 280
using namespace std;

int main(int argc, char  *argv[]) {
  string in;
  int k = 0;
  while (!cin.eof()) {
    cout << k++ << endl;
    cin >> in;
    istringstream iss(in);
    int len;
    iss >> len;
    cout << "len = " << len << endl;
    double sum = 0.0;
    for (int i = 0; i <= MAX; i++) {
      sum += 1.0/(i + 1);
      if (sum >= len) {
        if (i != 0)
          cout << i << " card(s)" << endl;
        break;
      }
    }
  }
  return 0;
}
