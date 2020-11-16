#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  double ans = (sy * gx + gy * sx) / (gy + sy);
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
