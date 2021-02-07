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

  // ### 入力例1
  //
  // .....
  // .###.
  // .###.
  // .###.
  // .....
  //
  // ### 探索する座標の範囲
  //
  // 左上のマス S(0,0) のマスの左上の頂点を vertex(0,0) とする。
  // 縦を x 軸、横を y 軸とする。
  // vertex(x,y) について x,y の取りうる範囲は以下である。
  //
  //   * 0 <= x <= H
  //   * 0 <= y <= W
  //
  // 一方で「マス目の一番外側のマス」は白に塗られていることが保証される。
  // そのため、探索する座標の範囲は以下の範囲でよい。
  //
  //   * 1 <= x <= H-1 (あるいは 1 <= x < H)
  //   * 1 <= y <= W-1 (あるいは 1 <= y < W)
  //
  // ### 判定方法
  //
  // 解説の通り、座標を囲んだ4マスについて、黒いマスの数を数える。
  //
  int ans = 0;
  for (int x = 1; x < h; x++) {
    for (int y = 1; y < w; y++) {
      int cnt = 0;
      // 左上
      if (s.at(x - 1).at(y - 1) == '#') {
        cnt++;
      }
      // 右上
      if (s.at(x - 1).at(y) == '#') {
        cnt++;
      }
      // 右下
      if (s.at(x).at(y) == '#') {
        cnt++;
      }
      // 左下
      if (s.at(x).at(y - 1) == '#') {
        cnt++;
      }
      if (cnt == 1 || cnt == 3) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
