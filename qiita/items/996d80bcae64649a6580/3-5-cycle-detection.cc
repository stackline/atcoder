#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  // 頂点数（サイクルを一つ含むグラフなので辺数は N で確定）
  int N;
  cin >> N;

  // グラフ入力受取
  Graph G(N);
  vector<int> deg(N, 0); // 各頂点の出次数
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a--; // 0-indexed にする
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
    deg.at(a)++;
    deg.at(b)++;
  }

  // leaf nodes をキューに挿入する
  // 今回は無向グラフなので、deg[v] == 1 が leaf node の条件になる
  queue<int> que;
  for (int v = 0; v < N; v++) {
    if (deg[v] == 1) {
      que.push(v);
    }
  }

  // BFS 開始
  vector<bool> is_pushed(N, false);
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    is_pushed[v] = true;

    for (int nv : G.at(v)) {
      deg.at(nv)--;
      if (deg.at(nv) == 1) {
        que.push(nv);
      }
    }
  }

  // クエリに答える
  int Q;
  cin >> Q;
  for (int _ = 0; _ < Q; _++) {
    int a, b;
    cin >> a >> b;
    a--; // 0-indexed にする
    b--;
    // 二頂点がともにサイクル上にある場合
    if (is_pushed.at(a) == false && is_pushed.at(b) == false) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }

  return 0;
}
