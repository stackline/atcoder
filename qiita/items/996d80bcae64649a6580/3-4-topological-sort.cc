#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
  // 頂点数と辺数
  int N, M;
  cin >> N >> M;

  // グラフ入力受取
  Graph G(N);
  vector<int> deg(N, 0); // 各頂点の出次数
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    // 有向グラフ
    G.at(b).push_back(a); // 逆向きに辺を張る
    deg.at(a)++; // 出次数
  }

  // sink たちをキューに挿入する
  queue<int> que;
  for (int i = 0; i < N; i++) {
    if (deg.at(i) == 0) {
      que.push(i);
    }
  }

  // BFS 開始（キューが空になるまで探索を行う）
  vector<int> order;
  while (!que.empty()) {
    int v = que.front(); // キューから頂点を取り出す
    que.pop();
    order.push_back(v);

    // v へと伸びている頂点たちを探索する
    for (int nv : G.at(v)) {
      // 辺 (nv, v) を削除する
      deg.at(nv)--;

      // それによって nv が新たに sink になったらキューに挿入
      if (deg.at(nv) == 0) {
        que.push(nv);
      }
    }
  }

  // 答えをひっくり返す
  reverse(order.begin(), order.end());
  for (auto v : order) {
    cout << v << endl;
  }
  return 0;
}
