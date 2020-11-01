#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    int num = b - a + 1;
    if (num % 2 == 1) {
      // 奇数
      // 1,2,3,4,5
      // a=1, b=5, num=5
      ans += ((a + b) * (num - 1) / 2) + ((a + b) / 2);
    } else {
      // 偶数
      // 1,2,3,4,5,6
      // a=1, b=6, num=6
      ans += (a + b) * (num / 2);
    }
  }

  cout << ans << endl;
  return 0;
}
