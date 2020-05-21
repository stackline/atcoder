#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

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
    G.at(b).push_back(a);
  }

  // BFS のためのデータ構造
  vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 二部グラフかどうか
  bool is_bipartite = true;

  for (int v = 0; v < N; v++) {
    if (dist[v] != -1) continue; // v が探索済みならスルー

    dist[v] = 0;
    que.push(v);

    // BFS 開始（キューが空になるまで探索を行う）
    while (!que.empty()) {
      int v = que.front(); // キューから先頭頂点を取り出す
      que.pop();

      // v から辿れる頂点をすべて調べる
      for (int nv : G[v]) {
        if (dist[nv] == -1) {
          dist[nv] = dist[v] + 1;
          que.push(nv);
        } else {
          if (dist[v] == dist[nv]) {
            is_bipartite = false;
          }
        }
      }
    }
  }

  // 結果出力
  cout << (is_bipartite ? "Yes" : "No") << endl;
  return 0;
}
