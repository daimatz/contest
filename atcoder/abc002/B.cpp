#include <iostream>
using namespace std;

int main() {
  string W;
  cin >> W;

  for (int i = 0; i < W.size(); ++i) {
    char c = W[i];
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
      continue;
    }
    cout << c;
  }
  cout << endl;
}
