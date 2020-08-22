#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt_digits(ll n) {
  int digits = 0;
  while (n > 0) {
    n = n / 10;
    digits++;
  }
  return digits;
}

int main() {
  ll n;
  cin >> n;

  // 最大値 F(1, n) = n の桁数
  int ans = cnt_digits(n);
  for (ll i = 1; i*i < n; i++) {
    if (n % i != 0) { continue; }
    int a = cnt_digits(i);
    int b = cnt_digits(n%i);
    int c = max(a, b);
    ans = min(ans, c);
  }

  cout << ans << endl;
  return 0;
}
