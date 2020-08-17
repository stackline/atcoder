#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;

  x = abs(x);
  ll ans;

  // 0に向かって移動する際、0 到達回数より k が小さい場合
  // 最小値は k 回 -d 側に移動した座標となる
  if (k < x/d) {
    ans = x - d*k;
  // 0に向かって移動する際、0 到達回数より k が大きい場合
  } else {
    // 0付近到達までの移動回数
    ll e = x/d;
    k = k - e;
    x = x - (d*e);

    // 残り回数が偶数の場合は、ループするので、そのまま
    // 残り回数が奇数の場合は、1回移動する
    if (k % 2 == 1) { x = abs(x-d); }
    ans = x;
  }

  cout << ans << endl;
  return 0;
}
