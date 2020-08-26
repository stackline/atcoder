#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // n 頂点
  // m 辺
  int n, m;
  cin >> n >> m;

  // パス情報を双方向で管理する
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<vector<int>> b(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-indexed
    a.at(x).at(y) = 1;
    b.at(y).at(x) = 1;
  }

  // 初期順列
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order.at(i) = i;
  }

  // 順列全探索
  int ans = 0;
  do {
    // 頂点1を始点とすること (0-indexed の場合は 0)
    if (order.at(0) != 0) { continue; }

    bool ok = true;
    for (int i = 1; i < n; i++) {
      int from = order.at(i-1);
      int to = order.at(i);
      // 辺が存在する場合は、次のパスを検証する
      if (a.at(from).at(to)) { continue; }
      if (b.at(from).at(to)) { continue; }

      // 辺が存在しない場合は、順列で作成した有限列のパターンが
      // 成立しないため、false とする
      ok = false;
    }
    if (ok) { ans++; }
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
  return 0;
}
