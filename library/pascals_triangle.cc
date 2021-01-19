#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### パスカルの三角形
//
// パスカルの三角形を計算し、異なる arg_n 個の中から arg_k 個を選ぶ
// 組み合わせの数 arg_n C arg_k を返す。
//
// nCk は以下の二項係数の公式で計算する。
//
//   nCk = n-1 C k-1 + n-1 C k
//
// 計算途中で数値がオーバーフローする場合は要注意。
//
ll pascals_triangle(ll arg_n, ll arg_k) {
  vector<vector<ll>> dp(arg_n + 1, vector<ll>(arg_n + 1));

  for (ll n = 0; n < arg_n + 1; n++) {
    for (ll k = 0; k < n + 1; k++) {
      if (k == 0 || k == n) {
        dp.at(n).at(k) = 1;
      } else {
        dp.at(n).at(k) = dp.at(n - 1).at(k - 1) + dp.at(n - 1).at(k);
      }
    }
  }
  return dp.at(arg_n).at(arg_k);
}

int main() {
  //
  // 例: 6C2 の場合
  //
  // 6C2 = (6!) / (2! * (6-2)!)
  //     = (6*5*4*3*2*1) / (2*1) * (4*3*2*1)
  //     = (6*5) / (2*1)
  //     = 15
  //
  // ファンクションは以下のパスカルの三角形について、
  // 0-indexed で縦に6段目、0-indexed で左から2番目の値 6C2 = 15 を返す
  //
  // 0 |             1
  // 1 |           1   1
  // 2 |         1   2   1
  // 3 |       1   3   3   1
  // 4 |     1   4   6   4   1
  // 5 |   1   5  10  10   5   1
  // 6 | 1   6  15  20  15   6   1
  //   +---------------------------
  //     0   1   2   3   4   5   6
  //
  cout << pascals_triangle(6, 2) << endl;
  return 0;
}
