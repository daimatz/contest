#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

#define MAX_W 20
#define MAX_H 20

int w, h;
int sx, sy;

typedef pair<int, int> Pii;

char m[MAX_H][MAX_W]; // m[y][x]

// {{{

int main(int argc, char *argv[]) {
  string s;
  while (1) {
    queue<Pii> q;
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        scanf(" %c", &m[i][j]);
        if (m[i][j] == 'o')
          sx = j, sy = i;
      }

    q.push(Pii(sx, sy));

    while (1) {

    }
  }
  return 0;
}

// }}}
