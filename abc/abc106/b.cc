#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i = i+2) {
    int cnt = 0;
    for (int j = 1; j <= i; j++) {
      // 奇数 i について 1〜i までの数字で剰余を求める
      // 割り切れたら約数なのでインクリメント
      if (i % j == 0) { cnt++; }
    }
    if (cnt == 8) { ans++; }
  }

  cout << ans << endl;
  return 0;
}
