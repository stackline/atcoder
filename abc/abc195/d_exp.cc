#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<pair<ll, ll>> v, vector<ll> x, ll l, ll r) {
  // 使えない箱を除く
  vector<ll> box;
  for (int i = 0; i < (int)x.size(); i++) {
    if (i >= l && i <= r) {
      continue;
    }
    box.push_back(x.at(i));
  }

  // 残った箱を、小さい箱順 (Xi の昇順) に並べる。
  sort(box.begin(), box.end());

  // 価値の大きな荷物を、小さい箱に積み込んでいく
  ll ans = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)box.size(); j++) {
      ll w = v.at(i).first;
      ll x = box.at(j);
      // 箱に荷物が入れられる場合
      //
      // * 価値の合計を更新する
      // * 荷物を入れた箱の残り容量を 0 にする
      // * 次の荷物を探索する
      if (x > 0 && x >= w) {
        ans += v.at(i).second;
        box.at(j) = 0;
        break;
      }
    }
  }

  return ans;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll n, m, q;
  cin >> n >> m >> q;

  // 荷物
  //   first = 大きさ
  //   second = 価値
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v.at(i) = make_pair(x, y);
  }

  // 荷物を価値の大きい順にソートする
  sort(v.begin(), v.end(),
       [](auto &left, auto &right) { return left.second > right.second; });
  // for (int i = 0; i < n; i++) {
  //   cout << v.at(i).first << ", " << v.at(i).second << endl;
  // }

  // 箱
  vector<ll> x(m); // 箱に入れることができる荷物の大きさ
  for (int i = 0; i < m; i++) {
    cin >> x.at(i);
  }

  // クエリ
  vector<ll> l(q);
  vector<ll> r(q);
  for (int i = 0; i < q; i++) {
    cin >> l.at(i);
    cin >> r.at(i);
  }

  // 解答
  for (int i = 0; i < q; i++) {
    // l,r を予め 0-indexed にする
    ll lx = l.at(i) - 1;
    ll rx = r.at(i) - 1;
    // 全ての箱が使えない場合、荷物が入れられないので 0 を出力。
    if ((rx - lx - 1) == m) {
      cout << 0 << endl;
    } else {
      cout << solve(v, x, lx, rx) << endl;
    }
  }
  return 0;
}
