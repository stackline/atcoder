#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  // 内分点の公式
  // ref. https://mathtrain.jp/naibungaibun
  double ans = double(gy * sx + sy * gx) / (sy + gy);
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
