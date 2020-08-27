#include <bits/stdc++.h>
using namespace std;

// ### 計算量
// O(m + n + n! * (n-1)) --> O(n!)
int main() {
  int N; // <= 8
  int M; // <= 8 * (8 - 1) / 2 = 28
  cin >> N >> M;

  vector<vector<bool>> G(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--; // 0-indexed
    // 無向グラフ
    G.at(a).at(b) = true;
    G.at(b).at(a) = true;
  }

  // 順列用の配列データを作成する
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    v.at(i) = i;
  }

  // ソート済みのため、next_permutation で全パターンを検索する
  int ans = 0;
  do {
    // 0 から開始ではない組合せはスキップ
    if (v.at(0) != 0) {
      continue;
    }

    // 0 から開始のパターンについて、パスが全て存在するかチェック
    // 存在しなければ false とする
    bool enabling = true;
    for (int i = 0; i < (N - 1); i++) {
      int from = v.at(i);
      int to = v.at(i + 1);
      if (G.at(from).at(to) == false) {
        enabling = false;
      }
    }

    if (enabling) {
      ans++;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
  return 0;
}
