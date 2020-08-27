#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ### 計算量
// O(m + (n-1)! * n) --> O(m+n!) --> O(n!)
bool all_seen(vector<bool> seen) {
  auto f = [](bool v_seen) { return v_seen == true; };
  return all_of(seen.begin(), seen.end(), f);
}

void dfs(int &cnt, vector<vector<int>> &graph, vector<bool> seen, int v) {
  // 頂点vを訪問済みとする
  seen.at(v) = true;

  // ベースケース
  // 全頂点を巡回できる経路の場合、インクリメントする
  if (all_seen(seen)) {
    cnt++;
  }

  // 再帰ステップ
  // 頂点vから行ける各頂点 next_v について DFS で探索する
  for (auto next_v : graph.at(v)) {
    // next_v が探索済みの場合はスキップ
    if (seen.at(next_v) == true) { continue; }
    dfs(cnt, graph, seen, next_v);
  }
}

int main() {
  // 頂点数と辺数
  int n, m;
  cin >> n >> m;

  // グラフ入力受取
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--; // 0-indexed
    graph.at(a).push_back(b);
    // 無向グラフのため、逆方向の辺も true とする
    graph.at(b).push_back(a);
  }

#ifndef ONLINE_JUDGE
  for (int i = 0; i < n; i++) {
    cout << "# loop start" << endl;
    for (auto a : graph.at(i)) {
      cout << i << " " << a << endl;
    }
  }
#endif

  // 全頂点を「未訪問」に初期化する
  vector<bool> seen(n, false);

  // 頂点0 (0-indexed) を始点として探索を開始
  int cnt = 0;
  dfs(cnt, graph, seen, 0);

  cout << cnt << endl;
  return 0;
}
