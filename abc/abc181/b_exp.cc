#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(N)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  // ### 1 以上 3 以下の整数の和
  //
  // sum(1,2,3) = 6
  //
  // 「1 以上 3 以下の整数の和」は、以下の長方形の面積の半分である。
  //
  //   o\ooo
  //   oo\oo
  //   ooo\o
  //
  // \ を除いた、横軸の長さ a 縦軸の長さ b の長さは以下である。
  //
  //   a = (3 + 1) = 4
  //   b = 3
  //
  // これより「1 以上 3 以下の整数の和」は以下となる。
  //
  //   a * b / 2 = (4 * 3) / 2 = 6
  //
  // 1 以上 x 以下の整数の和は以下で求められる。
  //
  //   (x + 1) * x / 2
  //
  // ### 3 以上 5 以下の整数の和
  //
  // (1 以上 5 以下の整数の和) - (1 以上 2 以下の整数の和) で求められる。
  //
  ll ans = 0;
  ll a, b, c, d;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    c = (b + 1) * b / 2;
    d = (a - 1 + 1) * (a - 1) / 2;
    ans += c - d;
  }

  cout << ans << endl;
  return 0;
}
