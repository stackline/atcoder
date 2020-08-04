#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll max_val = -1000000;
  ll min_val = 1000000;
  ll sum_val = 0;

  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;

    max_val = max(max_val, a);
    min_val = min(min_val, a);
    sum_val += a;
  }

  cout << min_val << " " << max_val << " " << sum_val << endl;
  return 0;
}
