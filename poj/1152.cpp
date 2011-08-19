/*
 last updated: 2010/06/03 11:08:31
 */
#include <iostream>
using namespace std;

int max_div(int d) {
  if (d % 2 == 0) return 2;
  for (int i = 3; i * i <= d; i+=2)
    if (d % i == 0) return i;
  return d;
}

int c2i(char n) {
  if ('0' <= n && n <= '9')
    return (int) (n-'0');
  if ('A' <= n && n <= 'Z')
    return (int) (n-'A'+10);
  if ('a' <= n && n <= 'z')
    return (int) (n-'a'+26);
}

int f(char n) {
  int d = c2i(n);
  if (max_div(d) == d)
    return d+1;
}

int main(int argc, char *argv[]) {
  char n;
  while (cin >> n) {
    int k = f(n);
    if (k != -1)
      cout << k << endl;
    else
      cout << "such number is impossible!" << endl;
  }
  return 0;
}
