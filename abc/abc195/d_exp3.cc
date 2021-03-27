#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m, q;
  cin >> n >> m >> q;

  // 荷物
  vector<int> w(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> w.at(i) >> v.at(i);
  }
  // 箱
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x.at(i);
  }

  for (int qi = 0; qi < q; qi++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--; // 0-indexed
    // 利用可能な箱のみ抽出する
    vector<int> a;
    for (int i = 0; i < m; i++) {
      // l 以上 R 以下の箱は使えない
      if (i < l || i > r) {
        a.push_back(x.at(i));
      }
    }
    // 箱の大きさが小さい順に並べ替える
    sort(a.begin(), a.end());

    // 小さい箱から順番に、入れることが可能な荷物の中で価値が最大の箱を、入れていく
    vector<bool> used(n, false); // 箱の利用状況を管理する
    int ans = 0;
    for (int limit : a) {
      int item_idx = -1;
      int item_value = 0;
      // 荷物を順番に試していく
      for (int i = 0; i < n; i++) {
        // 利用済みの場合はスキップする
        if (used.at(i) == true) {
          continue;
        }

        int weight = w.at(i);
        int value = v.at(i);
        if (weight <= limit && value > item_value) {
          item_idx = i;
          item_value = value;
        }
      }

      // 箱に入れる最適な荷物が見つかった場合
      if (item_idx >= 0) {
        ans += item_value;
        used.at(item_idx) = true;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
