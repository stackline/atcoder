#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int l;
  cin >> l;

  vector<vector<ll>> dp(200, vector<ll>(200));
  for (int n = 0; n < 200; n++) {
    for (int k = 0; k < n + 1; k++) {
      if (k == 0 || k == n) {
        dp.at(n).at(k) = 1;
      } else {
        dp.at(n).at(k) = dp.at(n - 1).at(k - 1) + dp.at(n - 1).at(k);
      }
    }
  }

  cout << dp.at(l - 1).at(11) << endl;
  return 0;
}
