#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  ll ans = 0;   // max_x
  ll b = 0;     // sum_x
  ll max_b = 0; // sum_max
  ll s = 0;     // last_x

  for (int i = 0; i < n; i++) {
    // 0〜i回目の移動距離の累積和
    b = b + a.at(i);

    // ### max_b の初期値は「移動しない」ケースの 0 を最大値とする
    //
    // 仮に A=[-3, -2, -1] という入力例の場合、
    // 座標の移動方向は -3, -5, -6 と、常にマイナス方向に移動する。
    //
    // そのため、上記入力例ではi回目の移動中に座標が最大になるのは、
    // 移動前のタイミングである。
    //
    // i回目のスタート地点の座標 s から移動しない = s + 0 の座標が、
    // 最大値である。
    //
    // これより max_b の初期値を 0 としている。
    //
    max_b = max(max_b, b);
    ans = max(ans, s + max_b);

#ifndef ONLINE_JUDGE
    cout << "i: " << i << ", s: " << s << ", b: " << b << ", max_b: " << max_b
         << ", ans: " << ans << endl;
#endif

    // i回目の操作を行った後の座標
    s = s + b;
  }
  cout << ans << endl;
  return 0;
}
