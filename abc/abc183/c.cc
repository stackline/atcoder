#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> t(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t.at(i).at(j);
    }
  }

  vector<ll> route(n - 1);
  // 0-indexed で 0 番目、最初の都市を除いている
  for (int i = 0; i < n - 1; i++) {
    route.at(i) = i + 1;
  }

  ll ans = 0;
  do {
    ll sum = 0;

    ll from = 0;
    ll to = route.at(0);
    sum += t.at(from).at(to);

    for (int i = 0; i < n - 2; i++) {
      from = route.at(i);
      to = route.at(i + 1);
      sum += t.at(from).at(to);
    }

    from = route.at(n - 2);
    to = 0;
    sum += t.at(from).at(to);

    if (sum == k) {
      ans++;
    }
  } while (next_permutation(route.begin(), route.end()));

  cout << ans << endl;
  return 0;
}
