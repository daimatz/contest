#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<x<<endl;
using namespace std;

const int MAX_N = 15;

int T, N;
long long ans, C[MAX_N];
vector<int> S, P;

int Sean(vector<int> S) { // normal
  int sum = 0;
  for (vector<int>::iterator i = S.begin();
       i < S.end();
       i++) {
    //DEBUG(*i);
    sum += *i;
  }
  return sum;
}

int print(vector<int> p) {
  for (vector<int>::iterator i = p.begin();
       i < p.end(); i++)
    DEBUG(*i);
}

int Patrick(vector<int> P) { // xor
  int sum = 0;
  for (vector<int>::iterator i = P.begin();
       i < P.end();
       i++) {
    //DEBUG(*i);
    sum ^= *i;
  }
  return sum;
}

long long dev(int k) {
  vector<int> S, P;
  for (int i = 0; i < MAX_N; i++) {
    if (k & (1<<i)) {
      P.push_back(C[i]);
      //DEBUG(i);
    } else {
      S.push_back(C[i]);
    }
  }
  /**
   * cout << "P ----- " << endl;
   * print(P);
   * cout << "S ----- " << endl;
   * print(S);
   */
  //DEBUG(Patrick(P)); DEBUG(Patrick(S));
  if (Patrick(P) == Patrick(S))
    return Sean(S);
  return -1;
}

int main(int argc, char *argv[]) {
  scanf("%d", &T);
  for (int x = 1; x <= T; x++) {
    memset(C,0,sizeof(C));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%lld", &C[i]);
    }
    sort(C, C+N);//, greater<int>());
    for (int i = 1; i >= 0 && i < (1<<N); i++) {
      //DEBUG(i);
      if ((ans = dev(i)) != -1)
        break;
    }
    if (ans != -1) cout << "Case #" << x << ": " << ans << endl;
    else cout << "Case #" << x << ": " << "NO" << endl;
  }
  return 0;
}
