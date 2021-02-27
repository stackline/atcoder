#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n;
  cin >> n;

  // 1 <= n <= 8
  // 4 = 2**2
  // 8 = 2**3
  //
  set<ll> s;

  for (ll i = 2; i <= 100000; i++) {
    ll b = i;
    ll a = i * b;
    for (int j = 0; j < 35; j++) {
      if (a <= n) {
        // cout << "#####" << endl;
        // cout << "n: " << n << endl;
        // cout << "a: " << a << endl;
        // cout << "b: " << b << endl;
        // cout << "j: " << j + 2 << endl;
        s.insert(a);
      } else {
        break;
      }
      a = a * b;
    }
  }

  cout << (n - s.size()) << endl;
  return 0;
}
