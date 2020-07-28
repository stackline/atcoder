#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> R(n);
  for (int i = 0; i < n; i++) {
    cin >> R.at(i);
  }

  // O(n**2) > 10**10
  //
  // 5C2 = (5 * 4) / (2 * 1) = 10
  // 200000C2 = (200_000 * 199_999) / (2 * 1) < 10**11
  ll ans = -1000000000;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      ll dif = R.at(j) - R.at(i);
      ans = max(ans, dif);
    }
  }

  cout << ans << endl;
  return 0;
}
