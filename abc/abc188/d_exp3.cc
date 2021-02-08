#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, c;
  cin >> n >> c;

  map<ll, ll> events;
  for (int i = 0; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    events[a] += c;
    events[b + 1] -= c;
  }

  ll ans = 0;
  ll pre = 0;
  ll fee = 0;
  for (auto event : events) {
    ans += (event.first - pre) * min(c, fee);
    pre = event.first;
    fee += event.second;
  }
  cout << ans << endl;
  return 0;
}
