#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc_digit(ll n) {
  int digit = 0;
  // 120 --> 12
  // 12 --> 1
  // 1 --> 0
  while (n > 0) {
    n = n / 10;
    digit++;
  }
  return digit;
}

int main() {
  ll n;
  cin >> n;

  ll lim = ll(sqrt(n));
  for (ll i = lim; i >= 1; i--) {
    if (n % i == 0) {
      int a = calc_digit(i);
      int b = calc_digit(n/i);
      cout << max(a, b) << endl;
      return 0;
    }
  }

  return 0;
}
