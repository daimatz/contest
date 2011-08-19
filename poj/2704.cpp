/*
 last updated: 2010/07/07 05:42:02
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long count;
vector< vector<int> > b;
vector< vector<long long> > a;
int row;

void solve() {
  for (int i=row-1;i>=0;--i) {
    for (int j=row-1;j>=0;--j) {
      if (i!=row-1 || j!=row-1) {
        a[i][j]=0;
        int c=b[i][j];
        if (i+c < row)
          a[i][j]+=a[i+c][j];
        if (j+c < row)
          a[i][j]+=a[i][j+c];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  while (true) {
    cin >> row;
    if (row == -1)
      break;
    count = 0;
    b.clear(); a.clear();
    for (int i = 0; i < row; i++) {
      string s;
      cin >> s;
      vector<int> bt;
      vector<long long> at;
      for (int j = 0; j < row; j++) {
        bt.push_back((int) (s[j] - 48));
        at.push_back(0);
      }
      b.push_back(bt);
      a.push_back(at);
    }
    a[row-1][row-1] = 1;
    solve();
    cout << a[0][0] << endl;
  }
  return 0;
}
