#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(n + 2n) = O(3n) = O(n)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  // dp[y0][true]  = y0 が true となる (x0) の組み合わせの数
  // dp[y1][false] = y1 が false となる (x0, x1) の組み合わせの数
  // dp[y2][true]  = y2 が true となる (x0, x1, x2) の組み合わせの数
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  // 初期化
  dp.at(0).at(true) = 1;
  dp.at(0).at(false) = 1;
  for (int i = 0; i < n; i++) {
    string op = a.at(i);

    for (bool flag : {true, false}) {
      if (op == "AND") {
        // && true
        bool b1 = flag && true;
        dp.at(i + 1).at(b1) += dp.at(i).at(flag);
        // && false
        bool b2 = flag && false;
        dp.at(i + 1).at(b2) += dp.at(i).at(flag);
      } else {
        // || true
        bool b1 = flag || true;
        dp.at(i + 1).at(b1) += dp.at(i).at(flag);
        // || false
        bool b2 = flag || false;
        dp.at(i + 1).at(b2) += dp.at(i).at(flag);
      }
    }
  }

#ifndef ONLINE_JUDGE
  // ### 入力例1の場合、debug 用の cout は以下の文字列を出力する。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 3 | 1 |
  //   | 2 | 3 | 5 |
  //
  // Yi の値を i = 0 から順番に計算していく。
  // dp[2][true] は「Y2 が true となる組み合わせの数」を格納する。
  //
  // i=0
  //   Y0 = true の場合
  //     1パターンのみ
  //     dp[0][true] を 0 -> 1 に変更
  //   Y0 = false の場合
  //     1パターンのみ
  //     dp[0][false] を 0 -> 1 に変更
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //
  // i=1 (AND で計算する)
  //   Y0 = true の場合
  //     X1 = true の場合
  //       Y1 = true && true = true
  //       dp[1][true] に (dp[0][true] = 1) を加算
  //     X1 = false の場合
  //       Y1 = true && false = false
  //       dp[1][false] に (dp[0][true] = 1) を加算
  //
  //   Y0 = true は1パターン。
  //   Y0 = true から遷移可能なパターンは Y1 = true, Y1 = false。
  //   Y1 = true, Y1 = false に到達可能なパターン数として 1 を引き継ぐ。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 1 | 1 |
  //
  //   Y0 = false の場合
  //     X1 = true の場合
  //       Y1 = false && true = false
  //       dp[1][false] に (dp[0][false] = 1) を加算
  //     X1 = false の場合
  //       Y1 = false && false = false
  //       dp[1][false] に (dp[0][false] = 1) を加算
  //
  //   Y0 = false は3パターン。
  //   Y0 = false から遷移可能なパターンは Y1 = false, Y1 = false。
  //   Y1 = false に到達可能なパターン数として 2 を引き継ぐ。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 3 | 1 |
  //
  // i=2 (OR で計算する)
  //   Y1 = true の場合
  //     X2 = true の場合
  //       Y2 = true || true = true
  //       dp[2][true] に (dp[1][true] = 1) を加算
  //     X2 = false の場合
  //       Y2 = true || false = true
  //       dp[2][true] に (dp[1][true] = 1) を加算
  //
  //   Y2 が true というケースに、Y1 が true というケースから 2 を引き継ぐ。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 3 | 1 |
  //   | 2 | 0 | 2 |
  //
  //   Y1 = false の場合
  //     X2 = true の場合
  //       Y2 = false || true = true
  //       dp[2][true] に (dp[1][false] = 3) を加算
  //     X2 = false の場合
  //       Y2 = false || false = false
  //       dp[2][false] に (dp[1][false] = 3) を加算
  //
  //   Y1 = false となる (X0, X1) の組み合わせは3パターンある。
  //
  //   Y1 = false で X2 = true の場合、Y2 = true となる。
  //   つまり (X0, X1, true) の組み合わせの数は 3 パターンある。
  //   そのため Y2 = true となるパターンに 3 を加算する。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 3 | 1 |
  //   | 2 | 0 | 5 |
  //
  //   同様に Y1 = false で X2 = false の場合、Y2 = false となる。
  //   つまり (X0, X1, false) の組み合わせの数は 3 パターンある。
  //   そのため Y2 = false となるパターンに 3 を加算する。
  //
  //   | i | f | t |
  //   |-----------|
  //   | 0 | 1 | 1 |
  //   | 1 | 3 | 1 |
  //   | 2 | 3 | 5 |
  //
  cout << "| i | f | t |" << endl;
  cout << "|-----------|" << endl;
  for (int i = 0; i < (int)dp.size(); i++) {
    cout << "| " << i << " ";
    for (int j = 0; j < (int)dp.at(i).size(); j++) {
      cout << "| " << dp.at(i).at(j) << " ";
    }
    cout << "|" << endl;
  }
#endif
  cout << dp.at(n).at(true) << endl;
  return 0;
}
