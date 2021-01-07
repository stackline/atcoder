#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<vector<double>>>
    dp(101, vector<vector<double>>(101, vector<double>(101, 0)));

double f(int x, int y, int z) {
  if (x == 100 || y == 100 || z == 100) {
    return 0;
  }
  double a = double(x) * (dp.at(x + 1).at(y).at(z) + 1) / double(x + y + z);
  double b = double(y) * (dp.at(x).at(y + 1).at(z) + 1) / double(x + y + z);
  double c = double(z) * (dp.at(x).at(y).at(z + 1) + 1) / double(x + y + z);
  return a + b + c;
}

int main() {
  cin.tie(nullptr);

  // x=99,y=99,z=99
  //
  // ### 入力例1
  // f(99,99,99) =
  //   -- 金貨を引く確率 * 金貨を引いた時の操作回数の期待値
  //   (99 / (99+99+99)) * (f(100,99,99) + 1)
  //
  //   -- 銀貨を引く確率 * 銀貨を引いた時の操作回数の期待値
  //   + (99 / (99+99+99)) * (f(99,100,99) + 1)
  //
  //   -- 銅貨を引く確率 * 銅貨を引いた時の操作回数の期待値
  //   + (99 / (99+99+99)) * (f(99,99,100) + 1)
  //
  // ### 入力例2
  // f(98,99,99) =
  //   -- 金貨を引く確率 * 金貨を引いた時の操作回数の期待値
  //   (98 / (98+99+99)) * (f(99,99,99) + 1)
  //
  //   -- 銀貨を引く確率 * 銀貨を引いた時の操作回数の期待値
  //   + (99 / (98+99+99)) * (f(98,100,99) + 1)
  //
  //   -- 銅貨を引く確率 * 銅貨を引いた時の操作回数の期待値
  //   + (99 / (98+99+99)) * (f(98,99,100) + 1)

  int a, b, c;
  cin >> a >> b >> c;

  for (int x = 100; x >= 0; x--) {
    for (int y = 100; y >= 0; y--) {
      for (int z = 100; z >= 0; z--) {
        dp.at(x).at(y).at(z) = f(x, y, z);
      }
    }
  }

  cout << fixed << setprecision(9);
  cout << dp.at(a).at(b).at(c) << endl;
  return 0;
}
