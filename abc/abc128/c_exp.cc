#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(2**n * mn)
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> vec(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;

    vec.at(i).resize(k);
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--; // 0-indexed
      vec.at(i).at(j) = s;
    }
  }

  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p.at(i);
  }

  int ans = 0;
  // 全てのスイッチのon/offパターンを探索する
  for (int i = 0; i < (1 << n); i++) {
    bool ok = true;

    // 電球 0〜m-1 について、全ての電球が点灯するか確認する
    for (int j = 0; j < m; j++) {
      int switch_on_cnt = 0;
      for (auto s : vec.at(j)) {
        // ### 例
        // i=2の場合、2 を2進数に変換すると 10 になる
        //
        // 一方で電球 j につながっているスイッチが 0, 1 (0-indexed) とする
        //
        // vec[j][0] = 0
        // vec[j][1] = 1
        //
        // 1つ目の要素は 0 となる
        //
        // (2 & (1 << 0))
        // --> (2 & 1)
        // --> (10 & 01)
        // --> (00)
        // --> 0 となる
        //
        // 2つ目の要素は 1 となる
        //
        // (2 & (1 << 1))
        // --> (2 & (10))
        // --> (10 & 10)
        // --> (10)
        // --> 2 となる
        //
        // そのため switch_on_cnt がインクリメントされる
        //
        if (i & (1 << s)) {
          switch_on_cnt++;
        }
      }
      // 条件を満たさな場合は false フラグを立てる
      if (switch_on_cnt % 2 != p.at(j)) {
        ok = false;
        // 今回のパターンが条件を満たさないことを確認したので、
        // 残りの探索はスキップする
        break;
      }
    }
    // 全部点灯していたらインクリメント
    if (ok) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
