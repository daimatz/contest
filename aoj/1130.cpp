#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;
/**
 * int start_w;
 * int start_h;
 *
 * int ans;
 * typedef pair<int,int> pr;
 * int M;
 * int N;
 *
 *
 *
 * stack <pair<int,int> > s;
 *
 *
 * void black(pr p){
 *   ans++;
 *   x[p.first][p.second]=1;
 *
 *   for(int=0;i<4;i++){
 *     if(i=0){
 *       if(x()
 * }
 *
 * void solve(){
 *   s.push(pr(start_w,start_h));
 *   while(s.empty()){
 *     black(s.top());
 *   }
 * }
 *
 * int main(int argc, char *argv[]) {
 *
 *   return 0;
 * }
 */

#define MAX_W 20
#define MAX_H 20

char maze[MAX_W][MAX_H];
int w, h;
int sx, sy;
int cnt;

void search(int x, int y) {
//  DEBUG(sx); DEBUG(sy);
  if (maze[y][x] != '.')
    return;

  maze[y][x] = '!';
  cnt++;

  if (x+1 < w) search(x+1, y);
  if (x-1 >= 0) search(x-1, y);
  if (y+1 < h) search(x, y+1);
  if (y-1 >= 0) search(x, y-1);
}

int main() {
  while (1) {
    cnt = 0;
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        scanf(" %c", &maze[i][j]);
        if (maze[i][j] == '@') {
          sy = i; sx = j;
          maze[i][j] = '.';
        }
      }


    search(sx, sy);

    cout << cnt << endl;

  }

  return 0;
}
