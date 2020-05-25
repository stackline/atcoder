#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 頂点数と辺数
int N, M;

int dfs(Graph &G, vector<vector<bool>> &relationships, int v, vector<int> combination) {
  // ベースケース
  if (v == N) {
    // 派閥を構成できるかどうか確認する
    int size = (int) combination.size();

    // cout << "[";
    // for(auto i : combination) {
    //   cout << i;
    // }
    // cout << "]" << endl;
    // cout << "size : " << size << endl;

    // 0人の組合せ、考慮不要
    // 1人の組合せ、派閥の構成人数は1人となる
    if (size == 0 || size == 1) {
      return size;
    }
    // 2人以上の組合せ、面識の無い人同士の組合せが存在した場合NG
    for (int i = 0; i < size - 1; i++) {
      int x = combination.at(i);
      for (int j = i + 1; j < size; j++) {
        int y = combination.at(j);
        if (relationships[x][y] == false) {
          // cout << "(x, y) = (" << i << ", " << j << ")" << endl;
          return 0;
        }
      }
    }
    return size;
  }

  // 再帰ステップ
  // 対象メンバーを含めない場合
  int a = dfs(G, relationships, v + 1, combination);
  // 対象メンバーを含める場合
  combination.push_back(v);
  int b = dfs(G, relationships, v + 1, combination);

  return max(a, b);
}

int main() {
  cin >> N >> M;

  // グラフ入力受取
  // 合わせて、人間関係を初期化する
  Graph G(N);
  vector<vector<bool>> relationships(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-indexed
    // 無向グラフ
    G.at(x).push_back(y);
    G.at(y).push_back(x);
    // 人間関係が存在する場合 true をセット
    relationships[x][y] = true;
    relationships[y][x] = true;
  }

  vector<int> combination;
  int ans = dfs(G, relationships, 0, combination);
  cout << ans << endl;
  return 0;
}
