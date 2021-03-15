#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  ll ans = 0;

  // 1,234,567
  // 10**3 : 1,000
  if (n > 999) {
    ans += n - 999;
  }
  // 10**6 1,000,000
  if (n > 999999) {
    ans += n - 999999;
  }
  // 10**9 1,000,000,000
  if (n > 999999999) {
    ans += n - 999999999;
  }
  // 10**12 1,000,000,000,000
  if (n > 999999999999) {
    ans += n - 999999999999;
  }
  // 10**15 1,000,000,000,000,000
  if (n > 999999999999999) {
    ans += n - 999999999999999;
  }

  cout << ans << endl;
  return 0;
}
