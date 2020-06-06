#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, S;
  cin >> K >> S;

  int ans = 0;
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      int rest = S - (x + y);
      // z が表現できる値の範囲であれば、カウントアップする
      if (rest >= 0 && rest <= K) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
