#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok(ll dx, ll dy, ll r) {
  // 三平方の定理で求める斜辺の長さが、与えられた半径より短いかどうか
  return (dx * dx) + (dy * dy) <= (r * r);
}

ll f(ll x, ll y, ll r, ll y_to) {
  // ### y 座標の探索の開始位置
  //
  // 中心点から y 座標の正の方向に r 移動した座標 (x, y + r) について、
  // y + r > 0 の場合、y + r 以上で 10000 で割り切れる値の内、最も大きい値を、
  // 探索の開始位置とする。
  // 例えば、y + r = 12000 の場合、20000 から y 軸をマイナスの方向に探索する。
  //
  // y + r < 0 の場合も同様である。
  // 例えば、y + r = -11000 の場合、-10000 から y 軸をマイナスの方向に探索する。
  //
  ll y_from = y + r;
  if (y_from > 0) {
    ll rest = y_from % 10000;
    y_from += 10000 - rest;
  } else if (y_from < 0) {
    ll rest = y_from % 10000;
    y_from += abs(rest);
  }

  // ### x 座標の探索の開始位置
  //
  // 左側の探索開始位置を決める。
  // 右側の探索開始位置は、左側から 10000 ずらす。
  ll left_start;
  if (x > 0) {
    left_start = x - (x % 10000);
  } else if (x < 0) {
    left_start = x + abs(x % 10000);
  } else {
    left_start = x;
  }
  ll right_start = left_start + 10000;

  ll left_current = left_start;
  ll right_current = right_start;
  ll cnt = 0;

  // cout << "### f" << endl;
  // cout << "x:      " << x << endl;
  // cout << "y:      " << y << endl;
  // cout << "r:      " << r << endl;
  // cout << "y_from: " << y_from << endl;
  // cout << "y_to:   " << y_to << endl;
  // cout << "left_start:  " << left_start << endl;
  // cout << "right_start: " << right_start << endl;

  for (ll i = y_from; i >= y_to; i = i - 10000) {
    while (ok(left_current - x, i - y, r)) {
      // printf("(x,y) = (%lld, %lld)\n", left_current, i);
      left_current -= 10000;
    }
    while (ok(right_current - x, i - y, r)) {
      // printf("(x,y) = (%lld, %lld)\n", right_current, i);
      right_current += 10000;
    }
    cnt += (right_current - right_start) / 10000 +
           (left_start - left_current) / 10000;
  }

  return cnt;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  double xd, yd, rd;
  cin >> xd >> yd >> rd;

  // double 型変数に 0.0003 を代入した場合、変数内では 0.00029999999999999997...
  // としてデータが保持される。
  //
  // 0.00029999999999999997... を 10000 倍すると 2.9999999999999997... となる。
  //
  // これを long long 型に変換する際、小数部分を切り捨てる。
  // 本来 3 が返ってくることを期待するが、2 が返ってくるため、誤差が生じる。
  //
  // そのため、round で誤差を解消する。
  ll x = round(xd * 10000);
  ll y = round(yd * 10000);
  ll r = round(rd * 10000);

  // 上半分
  ll ans1 = f(x, y, r, y);
  // 下半分
  ll ans2 = f(x, -y, r, -y + 1);

  // cout << "ans1: " << ans1 << endl;
  // cout << "ans2: " << ans2 << endl;
  cout << (ans1 + ans2) << endl;
  return 0;
}
