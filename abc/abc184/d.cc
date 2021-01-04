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

// ### 計算量 (再帰関数の呼び出し回数)
//
// search
//   上限1枚:             4
//   上限2枚:            49
//   上限3枚:           814
//   上限4枚:        15,745
//   上限5枚:       330,754
//   上限6枚:     7,305,601
//   上限7枚:   166,864,702
//   10**9  : 1,000,000,000
//   上限8枚: 3,903,679,489
//
// memoize
//   上限1枚:             4
//   上限2枚:            25
//   上限3枚:            82
//   上限4枚:           193
//   上限5枚:           376
//   上限6枚:           649
//   上限7枚:         1,030
//   10**9  : 1,000,000,000
//   上限8枚:         1,537
//   上限100枚:   3,000,001
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

double memoize(int a, int b, int c, int cnt, double rate,
               vector<vector<vector<bool>>> &done,
               vector<vector<vector<double>>> &memo) {
  // ベースケース
  if (a == 100 || b == 100 || c == 100) {
    return cnt * rate;
  }

  // 再帰ステップ

  // ---------- メモ化 ----------
  if (done.at(a).at(b).at(c)) {
    // printf("[cache hit] a: %d, b: %d, c: %d\n", a, b, c);
    return memo.at(a).at(b).at(c);
  }
  // ---------- メモ化 ----------

  // 金貨を引いた場合
  double rate_a = rate * a / (a + b + c);
  double expected_a = memoize(a + 1, b, c, cnt + 1, rate_a, done, memo);
  // 銀貨を引いた場合
  double rate_b = rate * b / (a + b + c);
  double expected_b = memoize(a, b + 1, c, cnt + 1, rate_b, done, memo);
  // 銅貨を引いた場合
  double rate_c = rate * c / (a + b + c);
  double expected_c = memoize(a, b, c + 1, cnt + 1, rate_c, done, memo);

  double expected = expected_a + expected_b + expected_c;

  // ---------- メモ化 ----------
  done.at(a).at(b).at(c) = true;
  memo.at(a).at(b).at(c) = expected;
  // ---------- メモ化 ----------

  return expected;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c;
  cin >> a >> b >> c;

  // 全探索
  // double val = search(a, b, c, 0, 1.0);

  // メモ化
  // すでに計算したかどうか
  vector<vector<vector<bool>>> done(
      101, vector<vector<bool>>(101, vector<bool>(101)));
  vector<vector<vector<double>>> memo(
      101, vector<vector<double>>(101, vector<double>(101)));
  double val = memoize(a, b, c, 0, 1.0, done, memo);
  cout << fixed << setprecision(9);
  cout << val << endl;

  return 0;
}
