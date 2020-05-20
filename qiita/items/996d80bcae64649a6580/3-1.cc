#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
  // 頂点数と辺数
  int N, M;
  // 始点と終点
  int s, t;
  cin >> N >> M >> s >> t;

  // グラフ入力受取
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    // 有向グラフのため、コメントアウト
    // G.at(b).push_back(a);
  }

  // BFS のためのデータ構造
  vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 初期条件（頂点 s を初期ノードとする）
  dist[s] = 0;
  que.push(s); // s を橙色頂点にする

  // BFS 開始（キューが空になるまで探索を行う）
  while (!que.empty()) {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : G[v]) {
      if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  // 結果出力
  cout << (dist[t] == -1 ? "No" : "Yes") << endl;
  return 0;
}
