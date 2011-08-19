/*
 last updated: 2010/05/28 04:57:48
 */
#include <iostream>
#include <list>
using namespace std;

void printlist(list<int> lst) {
  list<int>::iterator it;
  for (it = lst.begin(); it != lst.end(); it++)
    cout << *it << endl;
}

int main(int argc, char *argv[]) {
  int n;
  while (1) {
    cin >> n;
    list<int> lst;
    int i;
    for (i = 0; i < n; i++) {
      lst.push_back(i+1);
    }
    list<int>::iterator it = lst.begin();
    for (i = 1; ; i++) {
      cout << "if " << i << "," << endl;
      while (lst.size() > 1) {
        for (int j = 0; j < i; j++) {
          it++;
          if (it == lst.end())
            it = lst.begin();
        }
        cout << *it << endl;
        it = lst.erase(it);
      }
      if (*it == 1)
        break;
    }
    cout << i << endl;
  }
  return 0;
}
