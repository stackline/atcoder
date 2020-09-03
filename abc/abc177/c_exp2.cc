#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 累積和を用いて区間和を計算する
int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<ll> b(n+1, 0); // 累積和
  int mod = 1000000007;

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    // 累積和テーブル
    // a |  1 2 3
    // b | 0 1 2 3
    b.at(i+1) = b.at(i) + a.at(i);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll left = a.at(i) % mod;
    ll right = (b.at(n) - b.at(i+1)) % mod;
    ans = ans + (left * right);
    ans = ans % mod;
  }

  cout << ans << endl;
  return 0;
}
