#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  double a, b;
  cin >> a >> b;

  double ans = 100 * (a - b) / a;
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
