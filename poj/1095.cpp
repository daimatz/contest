/*
 last updated: 2010/05/26 04:58:29
 */
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 19

long g[MAX];
long h[MAX];

int get_g(long n) {
  int k;
  for (k = 0; k <= MAX; k++) {
    if (g[k] > n)
      break;
  }
  return k-1;
}

void print_tree(long n, int k) {
  if (k == 0)
    return;
  if (k == 1) {
    cout << "X";
    return;
  }
  long sub_next, sub_start;
  int left_vec_num;
  sub_next = sub_start = g[k];
  for (left_vec_num = 0; left_vec_num < k; left_vec_num++) {
    sub_next += h[left_vec_num] * h[k-left_vec_num-1];
    if (n >= sub_next) {
      sub_start = sub_next;
    } else {
      break;
    }
  }
  long l = g[left_vec_num] + (n-sub_start) / h[k-left_vec_num-1];
  long r = g[k-left_vec_num-1] + (n-sub_start) % h[k-left_vec_num-1];

  if (l > 0) {
    cout << "(";
    print_tree(l, left_vec_num);
    cout << ")";
  }
  cout << "X";
  if (r > 0) {
    cout << "(";
    print_tree(r, k-left_vec_num-1);
    cout << ")";
  }
}

int main(int argc, char *argv[]) {
  h[0] = h[1] = 1;
  g[0] = 0, g[1] = 1;
  for (int i = 2; i < MAX; i++) {
    h[i] = 0;
    g[i] = 0;
    for (int j = 0; j < i; j++) {
      h[i] += h[i-j-1] * h[j];
      g[i] += h[j];
    }
  }
  while (1) {
    long n;
    cin >> n;
    if (n == 0) break;
    print_tree(n, get_g(n));
    cout << endl;
  }
  return 0;
}
