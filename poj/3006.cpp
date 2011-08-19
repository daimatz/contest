/*
 last updated: 2010/07/22 18:07:51
 */
#include <iostream>
#include <cstring>
#define DEBUG(x) cout<<"#DEBUG:: line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

//const int MAX_O = 536870910;
const int MAX_O = 10000;

long isprime[MAX_O+1];

void makeans() {
  //DEBUG(sizeof(isprime));
  memset(isprime,-1,sizeof(isprime));
  isprime[1] = 0;
  for (int j = 2; 2*j <= MAX_O; j++)
    isprime[2*j] = 0;
  for (int i = 3; i <= MAX_O; i+=2) {
    if (!isprime[i])
      continue;
    for (int j = 2; i*j <= MAX_O; j++)
      isprime[i*j] = 0;
  }
}

int main(int argc, char *argv[]) {
  makeans();
  /**
   * for (int i = 1; i <= MAX_O; i++) {
   *   if (isprime[i])
   *     cout << i << endl;
   * }return 0;
   */
  while (true) {
    int a, d, n;
    cin >> a >> d >> n;
    if (a == 0 && d == 0 && n == 0)
      break;
    while (n--) {
      while (!isprime[a])
        a += d;
      a += d;
    }
    a -= d;
    cout << a << endl;
  }
  return 0;
}
