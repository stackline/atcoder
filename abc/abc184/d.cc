#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### 操作回数の期待値
//
// 1回
//   銀貨を取り出す
//     1 * (銀99) / (金98 + 銀99 + 銅99) = 0.3344594594594595
//   銅貨を取り出す
//     1 * (銅99) / (金98 + 銀99 + 銅99) = 0.3344594594594595
// 2回
//   1回目に金貨を取り出す + 2回目に金貨・銀貨・銅貨のいずれかを取り出す
//   (a) 金貨 + 金貨の場合
//     2 * (金98 / (金98 + 銀99 + 銅99)) * (金99 / (金99 + 銀99 + 銅99))
//   (b) 金貨 + 銀貨の場合
//     2 * (金98 / (金98 + 銀99 + 銅99)) * (銀99 / (金99 + 銀99 + 銅99))
//   (c) 金貨 + 銅貨の場合
//     2 * (金98 / (金98 + 銀99 + 銅99)) * (銅99 / (金99 + 銀99 + 銅99))
//   (a) + (b) + (c) が、2回操作を行う際の期待値である。
//     2 * (金98 / (金98 + 銀99 + 銅99)) * (金99 / (金99 + 銀99 + 銅99))
//       + 2 * (金98 / (金98 + 銀99 + 銅99)) * (銀99 / (金99 + 銀99 + 銅99))
//       + 2 * (金98 / (金98 + 銀99 + 銅99)) * (銅99 / (金99 + 銀99 + 銅99))
//     => 2 * (金98 / (金98 + 銀99 + 銅99)) * ((金99 / (金99 + 銀99 + 銅99)) + (銀99 / (金99 + 銀99 + 銅99)) + (銅99 / (金99 + 銀99 + 銅99)))
//     => 2 * (金98 / (金98 + 銀99 + 銅99)) * ((金99 + 銀99 + 銅99) / (金99 + 銀99 + 銅99))
//     => 2 * (金98 / (金98 + 銀99 + 銅99)) * (1)
//     => 2 * (金98 / (金98 + 銀99 + 銅99))
//
double search(int a, int b, int c, int cnt, double rate) {
  // ベースケース
  if (a == 100 || b == 100 || c == 100) {
    return cnt * rate;
  }

  // 再帰ステップ
  // 金貨を引いた場合
  double rate_a = rate * a / (a + b + c);
  double expected_a = search(a + 1, b, c, cnt + 1, rate_a);
  // 銀貨を引いた場合
  double rate_b = rate * b / (a + b + c);
  double expected_b = search(a, b + 1, c, cnt + 1, rate_b);
  // 銅貨を引いた場合
  double rate_c = rate * c / (a + b + c);
  double expected_c = search(a, b, c + 1, cnt + 1, rate_c);

  return expected_a + expected_b + expected_c;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c;
  cin >> a >> b >> c;

  // 全探索
  double val = search(a, b, c, 0, 1.0);
  cout << fixed << setprecision(9);
  cout << val << endl;

  return 0;
}
