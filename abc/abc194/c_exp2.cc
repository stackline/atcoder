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

  // 入力データ例
  //
  //   n = 4
  //   A = {1, 2, 3, 4}
  //
  // 問題文の二重和について、(Ai,Aj) の組み合わせを一覧表にする。
  // 以下の表は、縦軸をi、横軸をj、対象の組み合わせを "o" とする。
  //
  //     1 2 3 4
  //   1 - - - -
  //   2 o - - -
  //   3 o o - -
  //   4 o o o -
  //
  // 上記表について、(i,j) = (1,1),(2,2),(3,3),(4,4) の組み合わせは、
  // (Ai - Aj) = 0 となる。
  //
  // これらより、問題文の二重和は、上記表の正方形の面積の半分と同じ値となる。
  //
  //   例えば (i,j) = (3,2) と (2,3) は、いずれも Ai と Aj の差の二乗であり、
  //   Ai, Aj の値に関わらず（プラスでもマイナスでも）、(Ai - Aj)**2 は同じ値である。
  //
  // 問題文の二重和は以下に変換できる。
  //
  //             n     n
  //   (1/2) * sigma sigma (Ai - Aj)**2
  //            i=1   j=1
  //
  // 数列の一般項を展開する。
  //
  //             n     n
  //   (1/2) * sigma sigma (Ai**2 + Aj**2 - 2 * Ai * Aj)
  //            i=1   j=1
  //
  // 数列を分割する。
  //
  //              n     n               n     n               n     n
  //   (1/2) * (sigma sigma (Ai**2) + sigma sigma (Aj**2) - sigma sigma (2 * Ai * Aj))
  //             i=1   j=1             i=1   j=1             i=1   j=1
  //
  // 第1項と第2項について、二重和を一重にする。
  //
  //                  n                   n               n     n
  //   (1/2) * (n * sigma (Ai**2) + n * sigma (Aj**2) - sigma sigma (2 * Ai * Aj))
  //                 i=1                 j=1             i=1   j=1
  //
  // 第1項と第2項について、i と j の取りうる値の範囲は同じであり、
  // 数列の和が同じ値であるため、1つにまとめる。
  //
  //                   n               n     n
  //   (1/2) * (2n * sigma (Ai**2) - sigma sigma (2 * Ai * Aj))
  //                  i=1             i=1   j=1
  //
  // 第2項について、乗算する値を数列の外に出す。
  //
  //                   n                   n           n
  //   (1/2) * (2n * sigma (Ai**2) - 2 * sigma (Ai * sigma (Aj)))
  //                  i=1                 i=1         j=1
  //
  //   n
  // sigma (Aj) を S と置くと、第2項は以下となる。
  //  j=1
  //
  //           n
  //   - 2 * sigma (Ai * S)
  //          i=1
  //
  // S を外に出す。
  //
  //               n
  //   - 2 * S * sigma (Ai)
  //              i=1
  //
  //   n
  // sigma (Ai) = S とすると (-2 * S**2) となる。
  //  i=1
  //
  // S を sigma に戻して、数式を以下に変形する。
  //
  //                   n                    n
  //   (1/2) * (2n * sigma (Ai**2) - 2 * (sigma (Ai))**2)
  //                  i=1                  i=1
  //
  // 両辺に 1/2 を掛ける
  //
  //         n                n
  //   n * sigma (Ai**2) - (sigma (Ai))**2
  //        i=1              i=1
  //
  ll left = 0;
  for (ll i = 0; i < n; i++) {
    left += a.at(i) * a.at(i);
  }

  ll right = 0;
  for (ll i = 0; i < n; i++) {
    right += a.at(i);
  }

  ll ans = (n * left) - (right * right);
  cout << ans << endl;
  return 0;
}
