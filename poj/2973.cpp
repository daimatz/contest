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
//String word
char word[1001][8];

char key[7];
int n;

int main(int argc, char *argv[]) {
  while(1){
  scanf("%d",&n);
  if(n==0) break;

  for(int i=0;i<n;i++){
  cin>>word[i];
//  DEBUG((int)strlen(word[i]));
}

  cin>>key;
  int blank=0;
  for(int i=0;i<(int)strlen(key);i++){
    if(key[i]=='_'){
      blank++;
  }
  }
//  DEBUG(word[0]);
  int ans=0;
  for(int i=0;i<n;i++){
    int num=0;
//    DEBUG(strlen(key));
    for(int j=0;j<(int)strlen(key);j++){

//      DEBUG((int)strlen(word[i]));

      for(int m=0;m<(int)strlen(word[i]);m++){
        if(word[i][m]==key[j]){
          /**
           * DEBUG(j);
           * DEBUG(m);
           */
          word[i][m]='/';
          num++;
          break;
        }
      }
    }
    /**
     * DEBUG((int)strlen(word[i])-num);
     * DEBUG((int)strlen(word[i]));
     * DEBUG(num);
     * DEBUG(blank);
     */

    if((int)strlen(word[i])-num<=blank){
      ans++;
      }


  }

  cout<<ans<<endl;

  }
  return 0;
}
