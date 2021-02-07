#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s.at(i);
  }

  //
  // 左上のマスを起点に、「右マス・下マス・右下マス」の4つのマスについて、
  // 黒マスの数をカウントする。
  //
  // 黒マスの数が 1 or 3 の場合、4つのマスの中心に位置する座標を頂点と判断して、
  // 角数を1増加させる。
  //
  int ans = 0;
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w - 1; j++) {
      int cnt = 0;
      for (int di = 0; di < 2; di++) {
        for (int dj = 0; dj < 2; dj++) {
          if (s.at(i + di).at(j + dj) == '#') {
            cnt++;
          }
        }
      }
      if (cnt == 1 || cnt == 3) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
