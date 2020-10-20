#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// endl: line break + buffer flush
// '\n': line break
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Do not use both "cin/cout" and "scanf/printf" at the same time.
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  vector<ll> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
  }
  {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(x.at(i));
    }
    cout << ans << endl;
  }
  {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += x.at(i) * x.at(i);
    }
    // printf("%.15f\n", sqrt(ans));
    cout << sqrt(ans) << endl;
  }
  {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, abs(x.at(i)));
    }
    cout << ans << endl;
  }
  return 0;
}
