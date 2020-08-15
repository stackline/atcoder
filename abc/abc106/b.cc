#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> v(201, 0);
  for (int i = 1; i <= n; i = i+2) {
    for (int j = 1; j <= i; j++) {
      // 奇数 i について 1〜i までの数字で剰余を求める
      // 割り切れたら約数なのでインクリメント
      if (i % j == 0) {
        v.at(i)++;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (v.at(i) == 8) { ans++; }
  }
  cout << ans << endl;
  return 0;
}
