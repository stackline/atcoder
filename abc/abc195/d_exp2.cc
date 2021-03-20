#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define DEBUG
#undef DEBUG

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m, q;
  cin >> n >> m >> q;

  // 荷物の大きさと価値
  vector<pair<ll, ll>> vp(n);
  for (int i = 0; i < n; i++) {
    ll w, v;
    cin >> w >> v;
    vp.at(i) = make_pair(w, v);
  }

  // 荷物を価値の降順に並べる
  sort(vp.begin(), vp.end(), [](pair<ll, ll> left, pair<ll, ll> right) {
    return left.second > right.second;
  });
#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    auto p = vp.at(i);
    cout << p.first << ", " << p.second << endl;
  }
#endif

  // 荷物を入れる箱の大きさ
  vector<ll> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x.at(i);
  }

  // クエリL,R
  vector<int> l(q);
  vector<int> r(q);
  for (int i = 0; i < q; i++) {
    cin >> l.at(i) >> r.at(i);
  }

  // 1クエリごと処理する
  for (int i = 0; i < q; i++) {
    // 利用可能な箱を取り分ける
    int lx = l.at(i) - 1; // 0-indexed
    int rx = r.at(i) - 1; // 0-indexed
    vector<ll> box;
    for (int j = 0; j < m; j++) {
      if (j >= lx && j <= rx) {
        continue;
      }
      box.push_back(x.at(j));
    }
    // 箱を昇順で並べ替える
    sort(box.begin(), box.end());

    // 各荷物を各箱に詰める
    ll ans = 0;
    for (int j = 0; j < n; j++) {
      auto p = vp.at(j);
      ll weight = p.first;
      ll value = p.second;
      for (int k = 0; k < (int)box.size(); k++) {
        if (weight <= box.at(k)) {
          ans += value;
          box.at(k) = 0;
          break;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
