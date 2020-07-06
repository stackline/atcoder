#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  vector<string> v(H);
  for (int i = 0; i < H; i++) {
    cin >> v.at(i);
  }

  // ビット全探索
  // 入力例1の場合は、2^2 * 2^3 = 32パターンの全探索となる
  // (H, W) = (00, 000) ~ (11, 111)
  int ans = 0;
  for (int h = 0; h < (1 << H); h++) {
    for (int w = 0; w < (1 << W); w++) {

      // 各パターンについて '#' 記号の数を数える
      int count = 0;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          // 1の場合、# が塗り替えられているとする
          if (((h >> i) & 1) == 0 &&
              ((w >> j) & 1) == 0 &&
              v.at(i).at(j) == '#') {
            count++;
          }
        }
      }

      if (count == K) { ans++; }
    }
  }

  cout << ans << endl;
  return 0;
}
