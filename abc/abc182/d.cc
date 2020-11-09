#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  // N回移動する
  // それぞれの回について、最終値と最大値を計算する
  ll sum_x;
  ll sum_max;
  ll last_x;
  ll max_x = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      sum_x = a.at(i);
      sum_max = a.at(i);
      last_x = a.at(i);
      max_x = max(max_x, a.at(i));
    } else {
      // i 回目の動作について、0 から i-1 回の動作の合計として、座標の移動距離を求める
      sum_x += a.at(i);
      // i 回目の動作について、0 から i-1 回の動作の中で x 座標が最大現プラスの方向へ移動する際の移動距離を求める
      sum_max = max(sum_max, sum_x);
      // i 回目の動作について、i-1 回目までの動作で到着した座標から、x 座標が最大となるタイミングで移動した際の座標を求める。
      // この時 i-1 回目より i 回目の移動の方が x 座標が最大限プラスの方向へ移動する可能性がある。
      // そのため、事前に sum_max で i 回目の移動距離を求めている。
      max_x = max(max_x, last_x + sum_max);
      // i+1 回目用に、現在の座標位置を移動させる。
      last_x = last_x + sum_x;
    }
  }

  cout << max_x << endl;
  return 0;
}
