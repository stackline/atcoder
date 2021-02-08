#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, c;
  cin >> n >> c;

  vector<pair<ll, ll>> event;
  for (ll i = 0; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    // ai - 1日目とa日目の間に料金がci円上がる
    event.emplace_back(a - 1, c);
    // bi日目とbi + 1日目の間に料金がci円下がる
    event.emplace_back(b, -c);
  }

  sort(event.begin(), event.end());

  ll ans = 0;
  ll fee = 0;
  ll time = 0;
  for (auto [x, y] : event) {
    //
    // ### 入力例1の場合
    //
    //   event[0] : 0, +4
    //   event[1] : 2, -4
    //   event[2] : 1, +4
    //   event[3] : 2, -4
    //
    // これを sort する。
    //
    //   event[0] : 0, +4
    //   event[1] : 1, +4
    //   event[2] : 2, -4
    //   event[3] : 2, -4
    //
    // シミュレートする。
    // * 事前にコストの増減を計算する
    // * 次に増減後のコスト x 経過期間で料金を求める
    //
    //   0日目(1日目の開始) --> 0日目(1日目の開始)
    //     コストの変動: 0 + 4 = 4
    //   0日目(1日目の開始) --> 1日目(2日目の開始)
    //     期間の料金:   (1-0) * 4 = 4
    //     コストの変動: 4 + 4 = 8
    //   1日目(2日目の開始) --> 2日目(3日目の開始)
    //     期間の料金:   (2-1) * 8 = 8 --> プライムの 6
    //     コストの変動: 8 - 4 = 4
    //   2日目(3日目の開始) --> 2日目(3日目の開始)
    //     コストの変動: 4 - 4 = 0
    //
    if (x == time) {
      // 同じ日のイベントの場合は、料金の変更のみ行う。
      fee += y;
    } else {
      // 別の日のイベントの場合は、経過日数 x 料金で、期間の料金を求める。
      ans += (x - time) * min(c, fee);
      time = x;
      fee += y;
    }
  }

  cout << ans << endl;
  return 0;
}
