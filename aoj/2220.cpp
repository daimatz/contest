#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

#define F(x) ((a)*(x)*(x)*(x) + (b)*(x)*(x) + (c)*(x) + d)
#define OUT(n,m) (cout << n << " " << m << endl)

int main(int argc, char *argv[]) {
  int k;
  scanf("%d", &k);
  while (k--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a < 0) {
      a = -a; b = -b; c = -c; d = -d;
    }

    int DD = b*b - 3*a*c; // determinant
    double alpha = (-b-sqrt(DD))/(3*a), beta = (-b+sqrt(DD))/(3*a);
    int f0 = F(0);
    double falpha = F(alpha), fbeta = F(beta);
    if (DD < 0 || falpha * fbeta > 0) {
      if (f0 < 0) OUT(1,0);
      else if (f0 > 0) OUT(0,1);
      else OUT(0,0);
      continue;
    } else if (DD == 0) {
      if (f0 < 0) OUT(3,0);
      else if (f0 > 0) OUT(0,3);
      else OUT(0,0);
    } else if (falpha * fbeta < 0) {
      // falpha > 0, fbeta < 0
      if (alpha < 0 && beta < 0) {
        if (f0 > 0) OUT(0,3);
        else if (f0 < 0) OUT(1,2);
        else OUT(0,2);
      } else if (alpha < 0 && beta > 0) {
        if (f0 > 0) OUT(2,1);
        else if (f0 < 0) OUT(1,2);
        else OUT(1,1);
      } else {
        if (f0 > 0) OUT(2,1);
        else if (f0 < 0) OUT(3,0);
        else OUT(2,0);
      }
    } else if (falpha == 0) {
      if (f0 > 0) OUT(0,3);
      else if (f0 < 0) OUT(3,0);
      else OUT(1,0);
    } else { // if (fbeta == 0)
      if (f0 > 0) OUT(3,0);
      else if (f0 < 0) OUT(0,3);
      else OUT(0,1);
    }
  }
  return 0;
}
