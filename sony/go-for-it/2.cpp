#include <cstdio>
#include <cmath>
using namespace std;

const long double EPS = 1.0e-12L;
const long double PRECISION = 1.0e-9L;

// ガンマ関数の被積分関数 f(a, t) = t^(a-1) * exp(-t)
long double f(long double a, long double t) {
  return powl(t, a-1L) * expl(-t);
}

// シンプソンの公式で \int [s, t] f(x) dx の近似値を求める
long double simpson(long double a, long double s, long double t, int N) {
  long double h = (t-s)/(2*N); // 分割の幅
  long double S = 0.0L;
  for (int i = 0; i < 2*N-1; i += 2) {
    long double p = s + i*(t-s)/(2*N), q = s + (i+1)*(t-s)/(2*N), r = s + (i+2)*(t-s)/(2*N);
    S += (h/3.0)*(f(a, p) + 4 * f(a, q) + f(a, r));
  }
  return S;
}

// ガンマ関数の値を求める
long double gamma(long double a) {
  // 大体 5 <= a < 10 くらいだと早いので
  // gamma(a+1) = a * gamma(a) を用いて変換
  if (a < 5L) return gamma(a+1) / a;

  // max 以降は f の関数値を 0 とみなす
  long double max = 1.0;
  while (f(a, max) > EPS*0.01)
    max += 1.0L;

  long double S, T = -1.0;
  int n = 1;
  while (true) {
    n *= 2;
    S = simpson(a, 0.0, max, n);
    if ((S > T && S-T < EPS) ||
        (T > S && T-S < EPS))
      break;
    T = S;
  }
  return S;
}

// 階乗
int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n-1);
}

// 整数とみなす
bool isInt(long double a, int n) {
  return ((n > a && (long double)n - a < PRECISION) ||
          (a > n && a - (long double)n < PRECISION));
}

int main(int argc, char *argv[]) {
  long double a;
  while (scanf("%Lf", &a) != EOF) {
    int n = (int)a; // intに変換するときは切り捨て
    if (isInt(a, n)) {
      printf("%d\n", factorial(n));
    } else if (isInt(a, n+1)) {
      printf("%d\n", factorial(n+1));
    } else {
      printf("%.8Lf\n", gamma(a+1L));
    }
  }

  return 0;
}
