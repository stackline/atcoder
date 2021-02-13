#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  // ### 入力例1 (n=12)
  // 12
  // (-11 + ... + 11) + 12
  // 3 + 4 + 5
  // (-2 + ... + 2) + 3 + 4 + 5
  //
  // ### 入力例2 (n=1)
  // 1
  // (0) + 1

  // ### 等差数列の和の公式
  // https://mathtrain.jp/tosanowa
  //
  // 初項: a
  // 公差: d
  // 項数: n
  // 等差数列の和: S = (1/2) * n * (2a + (n-1) * d)

  // 公差 d = 1 より「等差数列の和」の式を変形する。
  //
  //   S = (1/2) * n * (2a + n - 1)
  //
  // a 左辺に寄せる
  //
  //   2S = n * (2a + n - 1)
  //   2S = 2an + n**2 - n
  //   2an = 2S - n**2 + n
  //   a = (2S - n**2 + n) / (2n)
  //
  // 項数を n = 1 から入力例の値 N まで 1 ずつ増加させて、
  // a が整数になるかどうかを確認する。
  //
  //   a が整数である場合、問題文を満たすため、cnt を 1 増やす。
  //   a が整数でない場合、問題文を満たさないため、スキップする。
  //
  // 分子が 0 以下になった場合、それ以降は探索不要のため、処理を中断する。
  // この時点で、初項 a について「1 以上の整数で条件を満たす値のパターン数」
  // が求まる。
  //
  // 最後にパターン数を2倍にして出力する。
  //
  //   初項 a、項数 n、公差 1、総和 N を満たす数列がある。
  //   これは事前に求めた「パターン数」に含まれる数列である。
  //
  //     (a + ... + (a + (n-1))) = N
  //
  //   この数列に「-(a-1) 〜 +(a-1)」を加えた数列も、
  //   問題文の条件を満たす数列である。
  //
  //     「-(a-1) 〜 +(a-1) = 0」であるため、総和 N は増減しない。
  //     このパターンを、算出したパターン数に加える。

  // ### 計算回数
  // n = 10**12 の場合でもループ回数は 1,414,215
  //
  // 以下の式で分子を求めている。
  //
  //    ll numerator = (2 * n) - (i * i) + i;
  //
  // 「2 * n」より、最大値は約 2 * (10**12)
  // これに項数 i について「(i * i)」を減算する。
  // i の取りうる値は大きく見積もっても (2 * 10**6) 程度。
  //
  //   2 * 10**6 = 2,000,000
  //
  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    ll numerator = (2 * n) - (i * i) + i;
    ll denominator = 2 * i;
#ifndef ONLINE_JUDGE
    cout << "###" << endl;
    cout << "numerator:   " << numerator << endl;
    cout << "denominator: " << denominator << endl;
    cout << "devide:      " << (double)numerator / (double)denominator << endl;
#endif
    if (numerator <= 0) {
      break;
    }
    if (numerator % denominator == 0) {
      cnt++;
    }
  }

  ll ans = cnt * 2;
  cout << ans << endl;
  return 0;
}
