#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      //
      // 問題文の条件
      //
      //   -1 <= ((y[j] - y[i]) / (x[j] - x[i])) <= 1
      //
      // 2点の「x 座標の距離の絶対値」と「y 座標の距離の絶対値」を求める。
      // 絶対値同士の傾きの取りうる範囲は 0 以上であるため、以下の条件を満たせばよい。
      //
      //   0 <= (y 座標の距離の絶対値 / x 座標の距離の絶対値) <= 1
      //
      // 各項目に「x 座標の距離の絶対値」を掛けると、条件は以下となる。
      //
      //   0 <= (y 座標の距離の絶対値) <= (x 座標の距離の絶対値)
      //
      // 絶対値 >= 0 より、以下の条件を満たす場合に問題文の条件を満たす。
      //
      //   (y 座標の距離の絶対値) <= (x 座標の距離の絶対値)
      //
      // この条件で判定する場合、傾きを算出する必要がない。
      // 浮動小数点数を取り扱わないため、丸め誤差の影響を受けない。
      //
      // 一方で、傾きを浮動小数点数として算出した上で -1 以上 1 以下かどうかを
      // 判定する場合は、浮動小数点数の丸め誤差の影響を受けて、
      // 入力値によっては期待と異なる判定結果になる可能性がある。
      //
      int ax = abs(x.at(j) - x.at(i));
      int ay = abs(y.at(j) - y.at(i));
      if (ay <= ax) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
