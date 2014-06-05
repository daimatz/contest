#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 30000;

int N;
int S[MAX_N], E[MAX_N];

int normalize(int n) {
  if (n - (n / 100) * 100 == 60) n = (n / 100 + 1) * 100;
  return n;
}

void solve() {
  pair<int, int> term[MAX_N];
  for (int i = 0; i < N; ++i) {
    int s = (S[i] / 5) * 5;
    int e = normalize(E[i] % 5 == 0 ? E[i] : (E[i] / 5) * 5 + 5);
    term[i] = {s, e};
  }
  sort(term, term+N);

  vector<pair<int, int>> ans;
  int s = term[0].first, e = term[0].second;
  for (int i = 0; i < N; ++i) {
    if (term[i].first <= e) {
      e = max(e, term[i].second);
    } else {
      ans.push_back({s, e});
      s = term[i].first;
      e = term[i].second;
    }
  }
  ans.push_back({s, e});
  for (int i = 0; i < ans.size(); ++i) {
    printf("%04d-%04d\n", ans[i].first, ans[i].second);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d-%d", S+i, E+i);
  solve();
}
