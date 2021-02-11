#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  // dp[i][j]
  // i = x[i] まで決めた時
  // j = y[i] になる時の場合の数
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  // dpを初期化
  dp.at(0).at(true) = 1;
  dp.at(0).at(false) = 1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    // y0 (= x0) と x1 の組み合わせから、y1 の取りうるパターン数を数える
    // for (bool y_current : {true, false}) {
    //   bool y_next;
    //   if (s == "AND") {
    //     // AND true の場合
    //     y_next = y_current && true;
    //     dp.at(i + 1).at(y_next) += dp.at(i).at(y_current);
    //     // AND false の場合
    //     y_next = y_current && false;
    //     dp.at(i + 1).at(y_next) += dp.at(i).at(y_current);
    //   } else {
    //     // OR true の場合
    //     y_next = y_current || true;
    //     dp.at(i + 1).at(y_next) += dp.at(i).at(y_current);
    //     // AND false の場合
    //     y_next = y_current || false;
    //     dp.at(i + 1).at(y_next) += dp.at(i).at(y_current);
    //   }
    // }
    for (bool y_current : {true, false}) {
      for (bool x_next : {true, false}) {
        bool y_next;
        if (s == "AND") {
          y_next = y_current && x_next;
        } else {
          y_next = y_current || x_next;
        }
        dp.at(i + 1).at(y_next) += dp.at(i).at(y_current);
      }
    }
  }
  cout << dp.at(n).at(true) << endl;
  return 0;
}
