#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, s, d;
  cin >> n >> s >> d;

  bool can = false;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    if (x < s && y > d) {
      can = true;
      break;
    }
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
