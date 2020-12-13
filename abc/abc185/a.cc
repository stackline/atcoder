#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = min(a, b);
  ans = min(ans, c);
  ans = min(ans, d);
  cout << ans << endl;
  return 0;
}
