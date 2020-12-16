#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_valid_move(ll a, ll b, ll c, ll d) {
  if (a + b == c + d) {
    return true;
  }
  if (a - b == c - d) {
    return true;
  }
  if (abs(a - c) + abs(b - d) <= 3) {
    return true;
  }
  return false;
}

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  // 0手
  if (a == c && b == d) {
    cout << 0 << endl;
    return 0;
  }
  // 1手
  if (is_valid_move(a, b, c, d)) {
    cout << 1 << endl;
    return 0;
  }
  // 2手
  // * 1手目
  //   * 3マス以内を移動する
  //   * 4マス以上を移動する
  // * 2手目
  //   * 3マス以内を移動する
  //   * 4マス以上を移動する

  // 1手目で3マス以内を移動する
  for (int x = -3; x <= 3; x++) {
    for (int y = -3; y <= 3; y++) {
      // 4マス以上の移動は除く
      if (abs(x) + abs(y) >= 4) {
        continue;
      }
      // 1マス以上移動する
      if (x == 0 && y == 0) {
        continue;
      }
      // 移動先
      //
      // ### 補足
      //
      // スタート地点 (a,b) から横に x、縦に y だけ移動した
      // マスを (a2, b2) とする。
      // (a2, b2) には1手で移動できる。
      //
      // この (a2, b2) からゴール地点である (c, d) に移動可能か
      // is_valid_move function で判定する。
      ll a2 = a + x;
      ll b2 = b + y;
      if (is_valid_move(a2, b2, c, d)) {
        cout << 2 << endl;
        return 0;
      }
    }
  }

  // 1手目で4マス以上を移動する
  // 1手目の x 座標の移動距離を m とする。m は正負、両方の値を取る。
  //
  // a + b = c + d
  // --> a + m + b + m = c + d
  // --> 2m = c + d - a - b
  // --> m = (c + d - a - b) / 2
  //
  // a - b = c - d
  // --> a + m - (b - m) =  c - d
  // --> 2m = c - d - a + b
  // --> m = (c - d - a + b) / 2
  //
  // ### 補足
  //
  // * スタート地点 (a,b) から 1 手目で x 座標、y 座標に m マス移動する。
  // * 「1手目で4マス以上を移動する」ためには、以下のいずれかを満たす
  //   斜めの移動となる。
  //
  //   * a+b = c+d
  //   * a-b = c-d
  //
  // * これらより 1 手で移動するマスは (a+m, b+m) となる。
  // * 1手目で到達したマス (a+m, b+m) から ゴール地点 (c,d) に
  //   移動可能かを調べる。
  // * 移動可能かの判定は以下2つの式で行う。
  //
  //   * a+b = c+d
  //   * a-b = c-d
  //
  // * |a-c|+|b-d| <=3 で判定しないのは 「1手目で3マス以内を移動する」
  //   ケースの探索で探索済みであるため。
  // * 以下のどちらでも、到達可能なマスは同じ。
  //
  //   * 1手目で3マス以内を移動 --> 2手目で4マス以上を移動
  //   * 1手目で4マス以上を移動 --> 2手目で3マス以内を移動
  //
  if ((c + d - a - b) % 2 == 0) {
    cout << 2 << endl;
    return 0;
  }
  if ((c - d - a + b) % 2 == 0) {
    cout << 2 << endl;
    return 0;
  }

  // 3手
  // 最大3手でゴールに到達する
  cout << 3 << endl;
  return 0;
}
