#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    int n, x;
    cin >> n >> x;

    if (n == 0 && x == 0) { break; }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j + 1; k <= n; k++) {
          int sum = i + j + k;
          if (sum == x) {
            ans++;
          }
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
