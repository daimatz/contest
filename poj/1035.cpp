/*
 last updated: 2010/06/21 09:42:42
 */
#include <iostream>
#include <list>
using namespace std;

int dis(string in, string word) {
  char c[0];
  for (c[0] = 'a'; c[0] <= 'z'; c[0]++) {
    string s = c;
    if (s + in == word || in + s == word || s + word == in || word + s == in)
      return 1;
  }
  return 2;
}

void printlist(list<string> dic) {
  for (list<string>::iterator it = dic.begin();
       it != dic.end();
       it++) {
    cout << *it << endl;
  }
}

int main(int argc, char *argv[]) {
  string in;
  list<string> dic;
  while (cin >> in) {
    if (in == "#")
      break;
    dic.push_back(in);
  }
  dic.sort();
  printlist(dic);

  while (cin >> in) {
    if (in == "#")
      break;
  }
  return 0;
}
