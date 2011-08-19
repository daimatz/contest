#include <iostream>
#include <pair>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  int cnt = 0;
  while (cin >> n && n > 0) {
    g.clear();
    cnt++;
    string c[n];
    for (int i = 0; i < n; i++)
      cin >> c[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
      string s, t;
      float f;
      cin >> s >> f >> t;
      add(s, f, t);
    }
    cout << "Case " << cnt << ": ";
    solve(c);
  }
  return 0;
}
