/*
 last updated: 2010/07/07 00:03:57
 */
#include <iostream>
using namespace std;

bool valid(int d, int b, int t) {
  bool f[t];
  for (int i = 0; i < t; i++)
    f[i] = false;
  for (int i = 0; i < t; i++) {
    int k = d % 10;
    d /= 10;
    f[k] = true;
  }
  for (int i = 0; i < b; i++)
    if (f[i] == false)
      return false;
  return true;
}

int pow10(int keta) {
  int ret = 1;
  while (keta--)
    ret *= 10;
  return ret;
}

int next(int d, int b, int keta) {
  do {
    d++;
    int w = 10;
    while (true) {
      int k = (d % w) / (w/10);
      if (k < b)
        break;
      d += (w - (k * (w/10)));
      w *= 10;
    }
  } while (!valid(d, b, keta));
  if (d >= pow10(keta))
    return -1;
  return d;
}

int sa(int val[], int h) {
  int max = -1, min = -1;
  for (int i = 0; i < h; i++) {
    if (max == -1 || max < val[i])
      max = val[i];
    if (min == -1 || min > val[i])
      min = val[i];
  }
  return max-min;
}

int main(int argc, char *argv[]) {
  string dummy;
  while (cin >> dummy) {
    int t, h;
    cin >> t >> h;
    int v[h][t];
    for (int i = 0; i < h; i++)
      for (int j = 0; j < t; j++)
        cin >> v[i][j];
    int pat = -1, minsa = -1, ansval[h], anspat[t];
    for (int i = 0; i < h; i++)
      ansval[i] = 0;
    while ((pat = next(pat, h, t)) >= 0) {
      int p = pat, val[h], tmppat[t];
      for (int i = 0; i < h; i++)
        val[i] = 0;
      for (int i = t-1; i >= 0; i--) {
        int idx = p % 10;
        tmppat[i] = idx;
        p /= 10;
        val[idx] += v[idx][i];
      }
      int s = sa(val, h);
      if (minsa == -1 || s < minsa) {
        minsa = s;
        for (int i = 0; i < t; i++) {
          if (i < h)
            ansval[i] = val[i];
          anspat[i] = tmppat[i];
        }
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < t; j++)
        if (anspat[j] == i)
          cout << (j+1) << " ";
      cout << ansval[i] << endl;
    }
    cout << endl;
    cin >> dummy;
  }
  return 0;
}
