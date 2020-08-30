#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;

void dfs(const Graph &G, int v, int &group_num) {
  seen.at(v) = true; // v を訪問済にする
  group_num++;

  // v から行ける各頂点 next_v について
  for (auto next_v : G.at(v)) {
    if (seen.at(next_v)) continue; // next_v が探索済だったらスルー
    dfs(G, next_v, group_num); // 再帰的に探索
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
    a--; b--; // 0-indexed

    G.at(a).push_back(b);
    // 無向グラフの場合は以下を追加
    G.at(b).push_back(a);
  }

  // 頂点 0 をスタートとした探索
  seen.assign(N, false); // 全頂点を「未訪問」に初期化

  int ans = 0;
  for (int i = 0; i < N; i++) {
    // 訪問済みの場合はスキップ
    if (seen.at(i)) { continue; }

    int group_num = 0;
    dfs(G, i, group_num);
    ans = max(ans, group_num);
  }

  cout << ans << endl;
  return 0;
}
