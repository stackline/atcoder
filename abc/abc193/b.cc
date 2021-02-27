#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  bool ok = false;
  int ans = 1000000000;
  for (int i = 0; i < n; i++) {
    int a, p, x;
    cin >> a >> p >> x;

    int rest = x - a;
    if (rest > 0) {
      ans = min(p, ans);
      ok = true;
    }
  }

  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
