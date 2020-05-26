#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順

void dfs(const Graph &G, int v, int &first_ptr, int &last_ptr) {
  // 行きがけ順をインクリメントしながらメモ
  first_order.at(v) = first_ptr++;

  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G.at(v)) {
    if (seen[next_v]) continue; // next_v が探索済だったらスルー
    dfs(G, next_v, first_ptr, last_ptr); // 再帰的に探索
  }

  // 帰りがけ順をインクリメントしながらメモ
  last_order.at(v) = last_ptr++;
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
  first_order.resize(N);
  last_order.resize(N);
  int first_ptr = 0, last_ptr = 0;
  dfs(G, 0, first_ptr, last_ptr);

  // 各頂点 v の行きがけ順、帰りがけ順を出力
  for (int v = 0; v < N; v++) {
    cout << v << ": " << first_order.at(v) << ", " << last_order.at(v) << endl;
  }

  return 0;
}
