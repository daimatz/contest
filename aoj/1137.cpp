#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

string s1, s2;
int n1, n2;

int s2i(string s) {
  int tmp = 1, ret = 0;
  for (unsigned int i = 0; i < s.size(); i++) {
    switch (s[i]) {
    case 'm':
      ret += tmp * 1000; tmp = 1; break;
    case 'c':
      ret += tmp * 100; tmp = 1; break;
    case 'x':
      ret += tmp * 10; tmp = 1; break;
    case 'i':
      ret += tmp * 1; tmp = 1; break;
    default:
      tmp = s[i] - '0';
    }
  }
  return ret;
}

string i2s(int k) {
  string ret = "";
  //DEBUG(k);
  char s[] = {'i','x','c','m'};
  for (int i = 0; i < 4; i++) {
    int t = k % 10;
    k /= 10;
    string tmp = "";
    if (t >= 2) tmp = (t+'0');
    if (t != 0) tmp += s[i];
    //DEBUG(tmp);
    ret = tmp+ret;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  while (n--) {
    n1 = n2 = 0;
    cin >> s1 >> s2;
    n1 = s2i(s1);
    n2 = s2i(s2);
    cout << i2s(n1+n2) << endl;
  }
  return 0;
}
