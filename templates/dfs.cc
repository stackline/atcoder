#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;

void dfs(const Graph &G, int v) {
  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G.at(v)) {
    if (seen[next_v]) continue; // next_v が探索済だったらスルー
    dfs(G, next_v); // 再帰的に探索
  }
}

int main() {
  // 頂点数と辺数
  int N, M;
  cin >> N >> M;

  // グラフ入力受取
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    // 無向グラフの場合は以下を追加
    G.at(b).push_back(a);
  }

  // 頂点 0 をスタートとした探索
  seen.assign(N, false); // 全頂点を「未訪問」に初期化
  dfs(G, 0);
  return 0;
}
