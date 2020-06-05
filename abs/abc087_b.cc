#include <bits/stdc++.h>
using namespace std;

int main() {
  int c500, c100, c50, X;
  cin >> c500 >> c100 >> c50 >> X;

  int ans = 0;
  for (int i = 0; i <= c500; i++) {
    for (int j = 0; j <= c100; j++) {
      for (int k = 0; k <= c50; k++) {
        int sum = 500 * i + 100 * j + 50 * k;
        if (sum == X) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
