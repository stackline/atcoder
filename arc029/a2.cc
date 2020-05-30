#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N; // <= 4
  vector<int> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t.at(i);
  }

  int ans = 4 * 50; // 最大値をセットしておく
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < N; i++) {
      // 対象のビットが1の場合、左で肉を焼く
      // 対象のビットが0の場合、右で肉を焼く
      if (tmp >> i & 1) {
        left += t.at(i);
      } else {
        right += t.at(i);
      }
    }
    int time = max(left, right);
    ans = min(ans, time);
  }

  cout << ans << endl;
  return 0;
}
