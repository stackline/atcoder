#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.at(i) = make_pair(x, y);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        //
        // 3点 A(a, b), B(c, d), C(e, f) について、
        // A(a, b) を原点 (0, 0) に移動させる。
        // B, Cについて、A(a, b) と同じ距離、移動させる。
        //
        // A, B, C の座標は以下となる。
        //
        //   A(0, 0), B(c-a, d-b), C(e-a, f-b)
        //
        // B, C について、座標を xi, yi とする。
        //
        //   A(0, 0), B(x1, y1), C(x2, y2)
        //
        // 直線 AB と直線 AC の傾きが等しい場合、
        // A, B, C は同一直線上に存在する。
        //
        // AB, AC の傾きは以下である。
        //
        //   * ABの傾き = y1 / x1
        //   * ACの傾き = y2 / x2
        //
        // これより、以下が成立するとよい。
        //
        //   (y1 / x1) == (y2 / x2)
        //
        // 除算による小数の誤差発生を回避するため、
        // 乗算した値同士の比較に変える。
        //
        //   y1 * x2 == y2 * x1
        //
        ll x1, y1, x2, y2, x3, y3;
        tie(x1, y1) = p.at(i);
        tie(x2, y2) = p.at(j);
        tie(x3, y3) = p.at(k);

        x1 = x1 - x3;
        y1 = y1 - y3;
        x2 = x2 - x3;
        y2 = y2 - y3;
        // x3 = x3 - x3;
        // y3 = y3 - y3;

        if (y1 * x2 == y2 * x1) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
