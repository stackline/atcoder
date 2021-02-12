#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 時間計算量: O(2**K * (K + M))
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m;
  cin >> n >> m;

  vector<int> va(m);
  vector<int> vb(m);
  for (int i = 0; i < m; i++) {
    cin >> va.at(i) >> vb.at(i);
  }

  int k;
  cin >> k;

  vector<int> vc(k);
  vector<int> vd(k);
  for (int i = 0; i < k; i++) {
    cin >> vc.at(i) >> vd.at(i);
  }

  // bit 全探索で全探索を行う。
  // k <= 16 のため、最大で 2**16 = 65536 パターン
  //
  // from:
  //   0
  //   = 0000_0000_0000_0000
  // to:
  //   (2**16 - 1)
  //   = (65536 - 1)
  //   = 65535
  //   = 1111_1111_1111_1111
  int ans = 0;
  for (int tmp = 0; tmp < (1 << k); tmp++) {
    // 空のお皿を用意する。
    // 1-indexed に対応するため、要素数を n+1 で初期化する。
    // 0番目の要素は使わない。
    vector<int> dish(n + 1);
    for (int i = 0; i < k; i++) {
      // bit フラグが立っている場合 Ci の皿
      // bit フラグが立っていない場合 Di の皿
      if (tmp & (1 << i)) {
        dish.at(vc.at(i))++;
      } else {
        dish.at(vd.at(i))++;
      }
    }

    // ボールを置き終わった状態で、条件を満たす数を数える。
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      if (dish.at(va.at(i)) > 0 && dish.at(vb.at(i)) > 0) {
        cnt++;
      }
    }

    // 「条件を満たす数が、より大きくなる置き方のパターン」を採用する。
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
