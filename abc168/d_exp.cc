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
    a--; b--; // 0-indexed
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  // BFS のためのデータ構造
  vector<int> pre(N, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 初期条件（部屋1は洞窟の入り口がある特別な部屋）
  pre[0] = 0;
  que.push(0); // 0 を橙色頂点にする

  // BFS 開始（キューが空になるまで探索を行う）
  while (!que.empty()) {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : G[v]) {
      if (pre[nv] != -1) continue; // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について、最短経路で帰れる部屋番号をセットする
      pre[nv] = v;
      que.push(nv);
    }
  }

  // 結果出力
  for (int v = 0; v < N; v++) {
    if (pre[v] == -1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for (int v = 1; v < N; v++) {
    cout << pre[v] + 1 << endl; // 1-indexed
  }
  return 0;
}
