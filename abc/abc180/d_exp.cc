#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// endl: line break + buffer flush
// '\n': line break
// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Do not use both "cin/cout" and "scanf/printf" at the same time.

  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll ans = 0;
  //
  // 強さが y 以上になるまで、カコモンジムに通い続けるパターンを探索する。
  //
  // 探索の途中で、カコモンジムより AtCoder ジムに通う方が、
  // 「強さ」の増加が低くなる状況がある。
  //
  // この状況に到達すると、AtCoder ジムに通う方が
  // 「強さ」の増加が抑えられるため、ジムに通える回数が多く、
  // 経験値を増やすことができる。
  //
  // ### 入力例2の場合
  //
  // x = 1
  // y = 1000000000000000000
  // a = 10
  // b = 1_000_000_000
  //
  // カコモンジムに9回通った時点で、強さは 10**9 となる。
  //
  //   x * a**9 = 1 * 10**9 = 1_000_000_000
  //
  // この状況でカコモンジムと AtCoder ジムに1回通った後の強さは、
  // それぞれ以下となる。
  //
  //   [カコモンジム]
  //   10**9 * a
  //   = 10**9 * 10
  //   = 10**10
  //
  //   [AtCoder ジム]
  //   10**9 + b
  //   = 1_000_000_000 + 1_000_000_000
  //   = 2_000_000_000
  //   = 10**9 * 2
  //
  // AtCoder ジムに通った後、カコモンジムに通うパターンは、
  // その逆より強さが増加してしまうため、
  // カコモンジムに最初に通うパターンを考える。
  //
  // カコモンジムに通いつつ、カコモンジムより AtCoder ジムの方が
  // 強さの増加割合が低くなった時点で、AtCoder ジムに切り替える。
  //
  while ((double)x * a <= 2e18 && x * a < y && x * a <= x + b) {
    x *= a;
    ans++;
  }

  // カコモンジムに通える最大の回数 ans と
  // AtCoder ジムに通える最大の回数の和を出力する。
  //
  // (y - x) / b とせず、分子を -1 しているのは、
  // 「強さが Y 以上にならないように」するため。
  // 最大でも y - 1 以下になるような AtCoder にジムに通える
  // 最大の回数を求める。
  cout << ans + (y - 1 - x) / b << endl;
  return 0;
}
