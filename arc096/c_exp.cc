#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 0;
  int n = max(X, Y);
  for (int i = 0; i <= (n * 2); i = i + 2) {
    int ab = i;
    int a = max((X - (ab / 2)), 0);
    int b = max((Y - (ab / 2)), 0);
    int amount = A * a + B * b + C * ab;

    if (ans == 0) {
      ans = amount;
    } else {
      ans = min(ans, amount);
    }
  }

  cout << ans << endl;
  return 0;
}
