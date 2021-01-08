#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int X = 100;
vector<vector<vector<double>>>
    dp(X + 1, vector<vector<double>>(X + 1, vector<double>(X + 1, 0)));

int main() {
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  for (int i = X - 1; i >= 0; i--) {
    for (int j = X - 1; j >= 0; j--) {
      for (int k = X - 1; k >= 0; k--) {
        // もらうDP
        //
        // 硬貨を1回引いて、金貨・銀貨・銅貨のいずれかである確率は 1 である。
        //
        //     金貨を引く確率 * 金貨を引いた操作1回
        //   + 銀貨を引く確率 * 銀貨を引いた操作1回
        //   + 銅貨を引く確率 * 銅貨を引いた操作1回
        //   = 1
        //
        // 以下の式は (a) * (b) で金貨・銀貨・銅貨のいずれかを取り出した際の
        // 期待値を算出し、「金貨・銀貨・銅貨のいずれかを取り出す」
        // という操作1回分を、最後に加算している。
        //
        //   (a) 各硬貨を引く確率
        //   (b) 各硬貨を引いた後、同種の硬貨が2枚袋に戻った状態の操作回数の期待値
        //
        double now = 0;
        now += dp.at(i + 1).at(j).at(k) * i;
        now += dp.at(i).at(j + 1).at(k) * j;
        now += dp.at(i).at(j).at(k + 1) * k;
        dp.at(i).at(j).at(k) = now / (i + j + k) + 1;
      }
    }
  }

  cout << fixed << setprecision(9);
  cout << dp.at(a).at(b).at(c) << endl;
  return 0;
}
