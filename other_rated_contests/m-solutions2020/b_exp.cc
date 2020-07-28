#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  bool can = false;
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K - i; j++) {
      for (int k = 0; k <= K - i - j; k++) {
        // 1 << 0 = 1   = 1
        // 1 << 1 = 10  = 2
        // 1 << 2 = 100 = 4
        int x = A * (1 << i);
        int y = B * (1 << j);
        int z = C * (1 << k);
        if (x < y && y < z) {
          can = true;
          break;
        }
      }
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
