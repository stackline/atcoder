#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // n スイッチの数
  // m 電球の数
  int n, m;
  cin >> n >> m;

  // 電球と、電球がつながっているスイッチ
  vector<set<int>> light_bulbs(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--; // 0-indexed
      light_bulbs.at(i).insert(s);
    }
  }

  // 点灯条件
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p.at(i);
  }

  int ans = 0;

  // スイッチの点灯パターンをbit探索する
  for (int tmp = 0; tmp < (1 << n); tmp++) {
    vector<set<int>> copied = light_bulbs;

    for (int i = 0; i < n; i++) {
      // i桁目のbitが1かどうか = i番目のスイッチがonかoffか
      // 1ではない場合、スイッチoffと見做す
      if (tmp & (1 << i)) {
        continue;
      } else {
        // 電球から対象のスイッチを off とする
        for (int j = 0; j < m; j++) {
          copied.at(j).erase(i);
        }
      }
    }

    // 全ての電球が点灯しているか確認する
    bool ok = true;
    for (int i = 0; i < m; i++) {
      // 条件を満たさない場合を探す
      if ((int)copied.at(i).size() % 2 != p.at(i)) {
        ok = false;
        break;
      }
    }
    if (ok) { ans++; }
  }

  cout << ans << endl;
  return 0;
}
