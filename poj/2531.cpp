#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  vector<int> a;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;
      if (j > i)
        a.push_back(tmp);
      // if (j <= i) then discards j;
    }
  }
  sort(a.begin(), a.end(), greater<int>());
  /**
   * long sum = 0;
   * for (vector<int>::iterator i = a.begin()+1;
   *      i != a.end();
   *      i++) {
   *   sum += *i;
   * }
   */
  cout << a[0]+a[1] << endl;
  return 0;
}
