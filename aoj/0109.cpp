#include <iostream>
#include <string>
#include <cctype>

using namespace std;

typedef string::const_iterator State;
class ParseError {};

int number(State &);
int term(State &);
int expression(State &);
int factor(State &);

int number(State &begin) {
  int ret = 0;
  while (isdigit(*begin)) {
    ret = (ret * 10) + (*begin - '0');
    begin++;
  }
  return ret;
}

int term(State &begin) {
  int ret = factor(begin);
  for (;;) {
    if (*begin == '*') ret *= factor(++begin);
    else if (*begin == '/') ret /= factor(++begin);
    else return ret;
  }
}

int expression(State &begin) {
  int ret = term(begin);
  for (;;) {
    if (*begin == '+') ret += term(++begin);
    else if (*begin == '-') ret -= term(++begin);
    else return ret;
  }
}

int factor(State &begin) {
  if (*begin == '(') {
    ++begin; // skip '('
    int ret = expression(begin);
    ++begin; // skip ')'
    return ret;
  } else {
    return number(begin);
  }
}

int main() {
  int N;
  string in;
  cin >> N;
  cin.ignore();
  while (N--) {
    getline(cin, in);
    State begin = in.begin();
    cout << expression(begin) << endl;
  }
  return 0;
}
