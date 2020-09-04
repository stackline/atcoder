#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 区間和を積み上げながら、面積を計算する
int main() {
  int n;
  cin >> n;
  int mod = 1'000'000'007;

  ll ans = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    // a[3] = [1, 2, 3] の場合
    //
    // i=0
    //   a=1
    //   ans = 0 + 1 * 0 = 0
    //   sum = 0 + 1     = 1
    // i=1
    //   a=2
    //   ans = 0 + 2 * 1 = 2
    //   sum = 1 + 2     = 3
    // i=2
    //   a=3
    //   ans = 2 + 3 * 3 = 11
    //   sum = 3 + 3     = 6
    //
    // ans の mod(10**9+7) を求める
    // 11 < 10**9+7 より ans = 11
    //
    ans = (ans + a * sum) % mod;
    sum = (sum + a) % mod;
  }

  cout << ans << endl;
  return 0;
}
