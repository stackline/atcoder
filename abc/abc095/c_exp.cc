#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(n)
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = 0;
  // max(x, y) 個だけ「ABピザ2枚セット」を購入すると、
  // x,y ともにノルマが満たされる
  for (int i = 0; i <= max(x, y); i++) {
    int amount = (c*2 * i) + (a * max(0, x-i)) + (b * max(0, y-i));
    if (ans == 0) {
      ans = amount;
    } else {
      ans = min(ans, amount);
    }
  }

  cout << ans << endl;
  return 0;
}
