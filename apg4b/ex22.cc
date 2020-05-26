#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> c(N);
  for (int i = 0; i < N; i++) {
    int a;
    int b;
    cin >> a >> b;
    // bでsortしたいので、bを第一要素とする
    c.at(i) = make_pair(b, a);
  }

  // bが小さい順にソートする
  sort(c.begin(), c.end());

  for (auto p : c) {
    cout << p.second << " " << p.first << endl;
  }
  return 0;
}
