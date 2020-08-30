#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }

  // b[0] = (1+2+...+n-1)
  // b[1] = (2+3+...+n-1)
  // b[n-1] = 0
  vector<ll> b(n);
  b.at(0) = sum - a.at(0);
  for (int i = 1; i < n; i++) {
    b.at(i) = b.at(i-1) - a.at(i);
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll w = b.at(i) % 1000000007;
    ll x = a.at(i) * w;
    // cout << i << " " << a.at(i) << " " << b.at(i) << " " << x << endl;
    ll y = x % 1000000007;
    ans += y;
  }

  ans = ans % 1000000007;
  cout << ans << endl;
  return 0;
}
