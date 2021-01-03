#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  ll a_sum = 0;
  vector<tuple<ll, ll, ll>> t(n);
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    a_sum += a;

    t.at(i) = make_tuple((a + a + b), a + b, a);
  }

  sort(t.rbegin(), t.rend());
  // for (int i = 0; i < n; i++) {
  //   ll x;
  //   ll y;
  //   ll z;
  //   tie(x, y, z) = t.at(i);
  //   cout << "x: " << x << endl;
  //   cout << "y: " << y << endl;
  //   cout << "z: " << z << endl << endl;
  // }

  int cnt = 0;
  ll b_sum = 0;
  for (int i = 0; i < n; i++) {
    ll x, y, z;
    tie(x, y, z) = t.at(i);
    b_sum += y;
    a_sum -= z;
    cnt++;
    if (b_sum > a_sum) {
      break;
    }
  }

  cout << cnt << endl;
  return 0;
}
