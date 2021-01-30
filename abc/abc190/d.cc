#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> enum_divisors(ll n) {
  set<ll> s;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  return s;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  set<ll> s = enum_divisors(n);
  ll ans = 0;
  for (ll a : s) {
    ll b = n / a;
    // 奇数の場合
    if (b % 2 == 1) {
      ans++;
    }
  }
  cout << ans * 2 << endl;
  return 0;
}
