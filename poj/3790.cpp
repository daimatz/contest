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

#define MAX_N 1000
long long table[MAX_N+1];

/**
 * int rec(int n) {
 *   if (table[n])
 *     return table[n];
 *
 *   REP(i, n/2) {
 *     table[n] += rec(i) * rec(n-2*i);
 *   }
 * }
 */

int main(int argc, char *argv[]) {
  int T;
  int memo[1001];
  memset(memo,0,sizeof(memo));
  memo[1]=1;
  for(int i=2;i<1001;i++){
    if(i%2){
      for(int j=1;j<=i;j=j+2){
        memo[i]+=memo[(i-j)/2];
      }
    }else{
      for(int j=0;j<=i;j+=2){
        memo[i]+=memo[(i-j)/2];
      }
    }
    memo[i]++;
  }
  /*
  for(int i=1;i<11;i++){
    printf("%d %d\n",i,memo[i]);
  }*/
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    int in;
    scanf("%d",&in);
    printf("%d %d\n",i,memo[in]);
  }
}
