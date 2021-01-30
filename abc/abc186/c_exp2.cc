#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    // range based for statement (範囲for文)
    for (int base : {8, 10}) {
      int x = i;
      while (x > 0) {
        int rest = x % base;
        if (rest == 7) {
          ok = false;
        }
        x = x / base;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
