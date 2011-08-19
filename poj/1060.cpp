/*
 last updated: 2010/06/24 17:01:35
 */
#include <iostream>
#define MAX 2000
using namespace std;

class poly {
public:
  int deg;
  int coe[MAX];
  poly(int d);
  void input();
  void print();
};

poly::poly(int d) {
  this->deg = d;
  for (int i = 0; i < d; i++)
    this->coe[i] = 0;
}

void poly::input() {
  int d = this->deg;
  while (d) {
    int k;
    cin >> k;
    coe[d-1] = k;
    d--;
  }
}

void poly::print() {
  int d = this->deg;
  cout << d;
  for (int i = d-1; i >= 0; i--) {
    cout << " " << this->coe[i];
  }
  cout << endl;
}

void calc(poly f, poly g, poly h) {
  poly m(f.deg+g.deg-1), n(f.deg+g.deg-1);
  for (int i = 0; i < f.deg; i++) {
    for (int j = 0; j < g.deg; j++) {
      m.coe[i+j] += f.coe[i] * g.coe[j];
      if (m.coe[i+j] == 2)
        m.coe[i+j] = 0;
    }
  }
  while (m.deg >= h.deg) {
    int q = m.deg - h.deg;
    for (int i = 0; i < h.deg; i++) {
      m.coe[i+q] += h.coe[i];
      if (m.coe[i+q] == 2)
        m.coe[i+q] = 0;
    }
    while (m.coe[m.deg-1] == 0)
      m.deg--;
  }
  m.print();
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d; poly f(d); f.input();
    cin >> d; poly g(d); g.input();
    cin >> d; poly h(d); h.input();
    calc(f,g,h);
  }
  return 0;
}
