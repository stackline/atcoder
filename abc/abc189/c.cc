#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  ll ans = 0;
  for (int from = 0; from < n; from++) {
    ll min_num = a.at(from);
    for (int to = from; to < n; to++) {
      min_num = min(min_num, a.at(to));
      ans = max(ans, (to - from + 1) * min_num);
    }
  }

  cout << ans << endl;
  return 0;
}
