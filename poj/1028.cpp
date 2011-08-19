#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class stack {
private:
  int counter;
  string contents[MAX];
public:
  stack() { counter = 0;}
  void push(string s);
  string pop();
  void clear();
};

void stack::push(string s) {
  contents[counter++] = s;
}

string stack::pop() {
  if (counter > 0)
    return contents[--counter];
  else
    return "\0";
}

void stack::clear() {
  counter = 0;
}

class browser {
private:
  stack backword;
  stack forward;
  string now;
public:
  bool go_url(string url);
  bool go_backword();
  bool go_forward();
  browser() { now = "http://www.acm.org/"; }
};

bool browser::go_url(string url) {
  backword.push(now);
  forward.clear();
  now = url;
  cout << url << endl;
  return true;
}

bool browser::go_backword() {
  string tmp;
  tmp = backword.pop();
  if (tmp == "\0") {
    cout << "Ignored" << endl;
    return false;
  } else {
    forward.push(now);
    now = tmp;
    cout << tmp << endl;
    return true;
  }
}

bool browser::go_forward() {
  string tmp;
  tmp = forward.pop();
  if (tmp == "\0") {
    cout << "Ignored" << endl;
    return false;
  } else {
    backword.push(now);
    now = tmp;
    cout << tmp << endl;
    return true;
  }
}

int main(int argc, char *argv[]) {
  string cmd;
  browser bro;
  while (1) {
    cin >> cmd;
    if (cmd == "VISIT") {
      string url;
      cin >> url;
      bro.go_url(url);
    } else if (cmd == "BACK") {
      bro.go_backword();
    } else if (cmd == "FORWARD") {
      bro.go_forward();
    } else if (cmd == "QUIT") {
      return 0;
    } else {
      return 1;
    }
  }
  return 0;
}
