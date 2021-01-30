#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());

  // ### 累積和
  // 5 1 2 --> 1 2 5
  //
  //  1 2 5
  // 0 1 3 8
  // -------
  // 0 1 2 3
  //
  vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) {
    s.at(i + 1) = s.at(i) + a.at(i);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    //
    // ### sigma(Aj) - (N-i) * Ai
    //
    //       2 - 1 = 1
    //   5     - 1 = 4
    //   5 - 2     = 3
    //
    // 上記3つの式について、「減数」ごとに差の値を求める。
    //
    //   減数が a.at(0) = 1 の時
    //     left:  被減数の和を、累積和で求める。計算量は O(1)
    //     right: 減数の登場回数をと求める。
    //     left - right で差を求める。
    //   減数が a.at(1) = 2 の時
    //   減数が a.at(2) = 5 の時
    //     同様の計算を行う。
    //
    ll left = s.at(n) - s.at(i + 1);
    ll right = (n - (i + 1)) * a.at(i);
    ans += left - right;
  }
  cout << ans << endl;
  return 0;
}
