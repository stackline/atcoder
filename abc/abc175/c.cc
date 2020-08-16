#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;

  while (k > 0) {
    if (x < 0) { x = x * -1; }

    if ((x-d) > 0) {
      ll a = x / d;
      ll b = min(a, k);

      k = k - b;
      x = x - (b*d);
    // (x-d) < 0
    } else {
      // 0 を挟んで、偶数回ループし、同じ地点に戻る
      ll c = k / 2;
      // 1回残っていれば、その分移動する
      ll e = k % 2;

      k = k - (c*2);
      x = x - (e*d);
      k = k - e;
    }
  }

  if (x > 0) {
    cout << x << endl;
  } else {
    cout << (x * -1) << endl;
  }
  return 0;
}
