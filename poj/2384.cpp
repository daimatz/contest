#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(it,s) for(__typeof((s).begin()) it = s.begin(); it != s.end(); it++)
#define ALLOF(a) a.begin(), a.end()
using namespace std;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8
char matrix[27][27];
int len[27][27];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cx[4]={-1,1,0,0};
int cy[4]={0,0,-1,1};
struct DATA
{
  int x,y;
  int fx,fy;
  int score;
  DATA(int a,int b,int c,int d,int e){
    x=a;y=b;fx=c;fy=d;score=e;
  }
};
int main(int argc, char *argv[]) {
  int N;
  scanf("%d",&N);
  for(int i=0;i<27;i++){
    for(int j=0;j<27;j++){
      len=INF;
    }
  }
  memset(matrix,0,sizeof(matrix));
  for(int i=0;i<N;i++){
    scanf("%s",&matrix[i+1][1]);
  }
  for(int i=0;i<27;i++){
    matrix[0][i]='#';
    matrix[i][0]='#';
    matrix[N+1][i]='#';
    matrix[i][N+1]='#';
  }
  int x,y;//* place
  for(int i=1;i<=N;i++){
    bool roop=false;
    if(roop)break;
    for(int j=1;j<=N;j++){
      if(matrix[i][j]=='*'){
        x=i;y=j;roop=true;
      }
    }
  }
  queue<DATA> q;
  for(int i=0;i<4;i++){
    q.push(DATA(x+dx[i],y+dy[i],x,y,1));
  }
  while(!q.empty()){
    DATA in=q.front();q.pop();
    int x=in.x,y=in.y,score=in.score;
    if(matrix[x][y]=='#')continue;
    if(score<len[x][y]){
      len[x][y]=score;
      for(int i=0;i<4;i++){
        if(in.fx==x+dx[i]&&in.fy==y+dy[i]){
          q.push(DATA(x+cx[i],y+cy[i],x,y,score+1));
        }else{
          q.push(DATA(x+cx[i],y+cy[i],x,y,score+3));
        }
      }
    }
  }
  return 0;
}
