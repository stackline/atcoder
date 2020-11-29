#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  // 0-indexed (0 <= i <= N-1) で入力値を保持する。
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  // 動作 i の合計の座標の変化
  vector<ll> p(n);
  // 動作 i を座標 0 で始めた場合の、開始から終了までの座標の最大値
  vector<ll> q(n);

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      p.at(i) = a.at(i);
      // a[0] が負の場合 0 が座標の最大値になる。
      q.at(i) = max(static_cast<ll>(0), p.at(i));
    } else {
      p.at(i) = a.at(i) + p.at(i - 1);
      // p[0]〜p[n-1] について、対象 index 番号以下の最大値を求める。
      q.at(i) = max(q.at(i - 1), p.at(i));
    }
  }

#ifndef ONLINE_JUDGE
  for (int i = 0; i < n; i++) {
    cout << "a: " << a.at(i) << ", p:" << p.at(i) << ", q: " << q.at(i) << endl;
  }
  return 0;
#endif

  // ### r
  // i回目までの移動で到達する、座標の最大値
  //
  // 例えば i=2 の場合は、以下の座標の内の最大値が
  // r にセットされる。
  //
  // * i=0 の移動で到達する座標の最大値
  // * i=1 の移動で到達する座標の最大値
  // * i=2 の移動で到達する座標の最大値
  //
  // 最終的には i=n-1 の場合に i=0〜n-1 の移動の中で
  // 到達した座標の最大値がセットされる。
  //
  // ### x
  // i回目の移動終了後の座標
  // 0回目の移動前の座標はスタート地点の 0 とする。
  //
  ll r = 0;
  ll x = 0;
  for (int i = 0; i < n; i++) {
    // ### r
    // i-1 回の移動の最中に到着した座標の最大値。
    //
    // ### x + q.at(i)
    // i-1 回の移動を行った後に到達する座標 x を起点に、
    // i 回目の移動の中で正の方向への最大の移動距離を
    // 加算することで、i 回目に到達可能な座標の最大値。
    //
    // ### max
    // 両者を比較し、i 回目の移動完了までに到達可能な
    // 座標の最大値を r にセットする。
    r = max(r, x + q.at(i));
    // i-1 回の移動を行った後に到達する座標 x に、
    // i 回目の移動の総和を加算することで、
    // i 回目終了後に到達する座標を求める。
    //
    // これを x に代入する。
    x = x + p.at(i);
  }
  cout << r << endl;
}
