#include <cstring>
#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int map['z'];

void init() {
  int s[] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,7,5,7};
  for (int i = 'a'; i < 'z'; i++) {
    map[i] = s[i-'a'];
  }
}

int score(const char s[]) {
  int sum = 0;
  for (unsigned int i = 0; i < strlen(s); i++) {
    sum += map[(int)s[i]];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  init();
  string s;
  int max = -1;
  while (cin >> s) {
    if (s == ".")
      break;
    int m = score(s.c_str());
    if (max < m)
      max = m;
  }
  cout << max << endl;
  return 0;
}
