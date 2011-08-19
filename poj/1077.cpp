/*
 last updated: 2010/05/26 08:46:22
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
using namespace std;
#define MAX 9

int u(int p[MAX], deque<char> q) {
  for (int i = 0; i < MAX; i++) {
    if (p[i] == 0) {
      if (i < 3)
        return 0;
      p[i] = p[i-3];
      p[i-3] = 0;
      break;
    }
  }
  q.push_back('u');
  return 1;
}

int d(int p[MAX], deque<char> q) {
  for (int i = 0; i < MAX; i++) {
    if (p[i] == 0) {
      if (i >= 6)
        return 0;
      p[i] = p[i+3];
      p[i+3] = 0;
      break;
    }
  }
  q.push_back('d');
  return 1;
}

int r(int p[MAX], deque<char> &q) {
  for (int i = 0; i < MAX; i++) {
    if (p[i] == 0) {
      if (i % 3 == 2)
        return 0;
      p[i] = p[i+1];
      p[i+1] = 0;
      break;
    }
  }
  q.push_back('r');
  return 1;
}

int l(int p[MAX], deque<char> &q) {
  for (int i = 0; i < MAX; i++) {
    if (p[i] == 0) {
      if (i % 3 == 0)
        return 0;
      p[i] = p[i-1];
      p[i-1] = 0;
      break;
    }
  }
  q.push_back('l');
  return 1;
}

int c(int p[MAX], int i) {
  return p[i] == i;
}

int check(int p[MAX]) {
  int flag = 1;
  for (int i = 0; i < MAX; i++)
    flag &= c(p, i);
  if (flag)
    return 1;
  if (c(p, 0) && c(p, 1) && c(p, 2))
    return 2;
  if (c(p, 0) && c(p, 1) && c(p, 2))
    return 3;
  return 0;
}

int solve(int p[MAX]) {
  deque<char> q;

}

int main(int argc, char *argv[]) {
  int p[MAX];
  int z;
  for (int i = 0; i < MAX; i++) {
    string x;
    int n;
    cin >> x;
    if (x == "x") {
      z = i;
      n = 0;
    }
    else
      n = atoi(x.c_str());
    p[i] = n;
  }
  for (int i = 0; i < 9; i++)
    cout << p[i] << endl;
  return 0;
}
