/*
 last updated: 2010/06/03 09:41:24
 */
#include <iostream>
#define MAX 1000000000
#define MAX_5N 13

using namespace std;

long pow5[MAX_5N] = {1,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};

long z(long d) {
  long n = 0;
  for (int i = 1; i < MAX_5N; i++) {
    n += d / pow5[i];
    if (d < pow5[i])
      break;
  }
  return n;
}

int main(int argc, char *argv[]) {
  long n;
  cin >> n;
  while (n--) {
    long d;
    cin >> d;
    cout << z(d) << endl;
  }
  return 0;
}
