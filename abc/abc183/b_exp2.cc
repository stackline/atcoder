#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  double ans = (sy * (gx - sx)) / (sy + gy) + sx;
  printf("%.10f\n", ans);
  return 0;
}
