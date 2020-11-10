#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<pair<int, int>> p(n);
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
        // 「直線 AB の傾き = 直線 AC の傾き」が成立する場合、
        // A, B, C は同一直線上に存在する。
        //
        // 直線 AB、直線 AC の傾きはそれぞれ以下である。
        //
        //   * 直線 AB の傾き = y1 / x1
        //   * 直線 AC の傾き = y2 / x2
        //
        // これらより、以下が成立する場合、A, B, C が
        // 同一直線上に存在する。
        //
        //   (y1 / x1) == (y2 / x2)
        //
        // 除算による小数の取り扱いを回避するため、
        // 乗算した値同士の比較に、式を変更する。
        //
        //   y1 * x2 == y2 * x1
        //
        int x1, y1, x2, y2, x3, y3;
        tie(x1, y1) = p.at(i);
        tie(x2, y2) = p.at(j);
        tie(x3, y3) = p.at(k);

        int dx1 = x1 - x3;
        int dy1 = y1 - y3;
        int dx2 = x2 - x3;
        int dy2 = y2 - y3;
        // int dx3 = x3 - x3;
        // int dy3 = y3 - y3;

        if (dy1 * dx2 == dy2 * dx1) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
