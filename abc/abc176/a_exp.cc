#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x, t;
  cin >> n >> x >> t;

  // n を x で割った剰余に (x-1) を加算するイメージ。
  // ceil を使わないのは double 型を利用すると誤差を気にする必要があるため。
  //
  // ### n % x = 0 の場合
  //
  // (n+x-1) % x = (x-1) となる。
  // (x-1) < x となる。
  // そのため、(n + (x-1)) / x で除算した際に (x-1) が切り捨てられる。
  // そのため、n / x と (n+x-1) / x で結果は変わらない。
  //
  // ### n % x > 0 の場合
  //
  // n % x = y とする。
  // 0 < y < x である。
  // n % x = y より、左辺の n に (x-1) を足すと (n+x-1) % x = (y+x-1) となる。
  //
  // 0 < y < x より右辺の (y+x-1) >= x である。
  // 剰余が x 以上であるため、(n+x-1) / x の結果は +1 となる。
  // そのため、n / x と (n+x-1) / x で結果が変わる。
  // (n+x-1) / x の方が +1 大きい。
  //
  int times = (n + x -1) / x;
  int ans = times * t;
  cout << ans << endl;
  return 0;
}
