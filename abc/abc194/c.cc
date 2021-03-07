#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  ll ans = 0;
  // Ai * Ai, Aj * Aj の方
  for (int i = 0; i < n; i++) {
    ans += (a.at(i) * a.at(i) * (n - 1));
  }

  // -2 * Ai * Aj の方
  ll sum = 0;
  for (int i = 1; i < n; i++) {
    sum += a.at(i - 1);
    ans += (-2 * a.at(i) * sum);
  }

  cout << ans << endl;
  return 0;
}
