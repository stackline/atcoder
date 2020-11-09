#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    // Ai=3, Bi=5 とした場合、sum(3,4,5) は以下の長方形の面積の半分となる。
    //
    //   ooo ooooo
    //   oooo oooo
    //   ooooo ooo
    //
    // 縦 = Bi - Ai + 1
    // 横 = Ai + Bi
    ans += (b - a + 1) * (a + b) / 2;
  }
  cout << ans << endl;
  return 0;
}
