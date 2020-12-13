#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll combination(ll n, ll k) {
  ll num = 1;
  for (ll i = 1; i <= k; i++) {
    cout << "i: " << i << ", num: " << num << endl;
    num = num * (n - i + 1) / i;
  }
  return num;
}

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll l;
  cin >> l;

  // 重複組合せ
  ll k = l - 12;
  ll n = k + 11;
  // int ans = combination(n, k);
  // cout << ans << endl;

  // ref.
  // https://algo-logic.info/pascal-triangle/
  // https://ja.stackoverflow.com/questions/60698/%E7%B5%84%E3%81%BF%E5%90%88%E3%82%8F%E3%81%9B%E8%A8%88%E7%AE%97%E3%81%A7-64c32-%E3%81%AE%E7%B5%90%E6%9E%9C%E3%81%8C%E3%82%AA%E3%83%BC%E3%83%90%E3%83%BC%E3%83%95%E3%83%AD%E3%83%BC
  // https://math.nakaken88.com/textbook/cp-pascal-triangle/
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  for (ll i = 0; i <= n; i++) {
    dp.at(i).at(0) = 1;
    for (ll j = 1; j <= i; j++) {
      // dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
      dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + dp.at(i - 1).at(j);
    }
  }

  cout << dp.at(n).at(k) << endl;
  return 0;
}
