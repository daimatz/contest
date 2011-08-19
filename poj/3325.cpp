/*
 last updated: 2010/07/13 03:22:53
 */
#include <iostream>
using namespace std;

int max_index(int in[], int n) {
  int max = 0, i;
  while (n--) {
    if (in[n] > max) {
      max = in[n];
      i = n;
    }
  }
  return i;
}

int min_index(int in[], int n) {
  int min = 1000, i;
  while (n--) {
    if (in[n] < min) {
      min = in[n];
      i = n;
    }
  }
  return i;
}

int main(int argc, char *argv[]) {
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    int in[n];
    for (int i = 0; i < n; i++)
      cin >> in[i];
    int ma = max_index(in, n), mi = min_index(in, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (i == ma || i == mi)
        continue;
      sum += in[i];
    }
    cout << sum / (n-2) << endl;
//    cout << "n: " << n << ", ma: " << ma << ", mi: " << mi << endl;
  }
  return 0;
}
