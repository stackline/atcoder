#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(vector<vector<int>> &graph, vector<bool> seen, int vertex) {
  // 頂点を訪問済みにする
  seen.at(vertex) = true;

  auto f = [](bool seen) { return seen == true; };
  bool all_seen = all_of(seen.begin(), seen.end(), f);
  if (all_seen) {
    return 1;
  }

  int cnt = 0;
  // vertex から訪問可能な頂点を探索する
  for (auto next_vertex : graph.at(vertex)) {
    // 次の頂点が訪問済みの場合はスキップ
    if (seen.at(next_vertex) == true) { continue; }
    cnt += dfs(graph, seen, next_vertex);
  }

  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;

  // 入力受取
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-indexed
    graph.at(x).push_back(y);
    graph.at(y).push_back(x); // 無向グラフ
  }

  // 訪問情報の初期化
  vector<bool> seen(n, false);

  // DFSで探索
  int cnt = dfs(graph, seen, 0);
  cout << cnt << endl;
  return 0;
}
