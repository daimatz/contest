#include <iostream>
#include <set>
using namespace std;

const set<char> replace = {'a','t','c','o','d','e','r'};
string S, T;

void solve() {
  for (int i = 0; i < S.size(); ++i) {
    if (!(S[i] == '@' && T[i] == '@')
      && (
        (S[i] == '@' && replace.count(T[i]) == 0)
        || (T[i] == '@' && replace.count(S[i]) == 0)
        || (S[i] != '@' && T[i] != '@' && S[i] != T[i]))
      ) {
      cout << "You will lose" << endl;
      return;
    }
  }
  cout << "You can win" << endl;
}

int main() {
  cin >> S >> T;
  solve();
}
