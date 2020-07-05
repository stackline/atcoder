#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll b_quotient = b / x;
  ll ans = 0;
  if (a == 0) {
    ans = b_quotient + 1;
  } else {
    ll a_quotient = (a - 1) / x;
    ans = b_quotient - a_quotient;
  }

  cout << ans << endl;
  return 0;
}
