#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 時間計算量:
//   forループ: O(N)
//   map への値の追加: O(logN)
//   合計: O(NlogN)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, c;
  cin >> n >> c;
  map<ll, ll> mp;
  for (ll i = 0; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    mp[a] += c;
    mp[b + 1] -= c;
  }

  ll ans = 0;
  ll current_day = 0;
  ll current_cost = 0;
  bool firstflag = true;
  for (auto x : mp) {
    if (firstflag == true) {
      firstflag = false;
      current_day = x.first;
      current_cost = x.second;
    } else {
      ll next_day = x.first;
      ll next_cost = current_cost + x.second;
#ifndef ONLINE_JUDGE
      cout << "current_day:  " << current_day << endl;
      cout << "current_cost: " << current_cost << endl;
      cout << "next_day:     " << next_day << endl;
      cout << "next_cost:    " << next_cost << endl;
      cout << "next_day - current_day:   " << next_day - current_day << endl;
      cout << "next_cost - current_cost: " << next_cost - current_cost << endl;
#endif
      ans += (next_day - current_day) * min(current_cost, c);
      current_day = next_day;
      current_cost = next_cost;
    }
  }

  cout << ans << endl;
  return 0;
}
