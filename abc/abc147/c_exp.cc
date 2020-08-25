#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  // 言及していない場合は-1
  vector<vector<int>> g(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int x, y;
      cin >> x >> y;
      x--; // 0-indexed
      g.at(i).at(x) = y;
    }
  }

  // bit全探索
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> d(n);
    // j人目の人が「1:正直者」か「0:不親切な人」か
    for (int j = 0; j < n; j++) {
      d.at(j) = ((i >> j) & 1);
    }

    bool ok = true;
    for (int j = 0; j < n; j++) {
      // j番目の人が「0:不親切な人」の場合はスキップ
      if (d.at(j) == 0) { continue; }
      // j番目の人が「1:正直者」の場合は、証言に矛盾がないか確認
      for (int k = 0; k < (int) g.at(j).size(); k++) {
        // k番目の人について証言していない場合は、スキップ
        if (g.at(j).at(k) == -1) { continue; }
        // k番目の人について証言と仮定が一致しない場合は、フラグを false にする
        if (g.at(j).at(k) != d.at(k)) { ok = false; }
      }
    }

    // 証言と矛盾が無ければ「1:正直者」の数をカウント
    // 最大の正直車の数を更新する
    if (ok) {
      ans = max(ans, __builtin_popcount(i));
    }
  }

  cout << ans << endl;
  return 0;
}
