#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, k;
  cin >> n >> k;
  vector<vector<int>> T(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> T.at(i).at(j);
    }
  }

  // 都市の番号を全て index に代入する。
  // 入力例 1 であれば、n=4 のため以下を代入する。
  //
  //   index = {0, 1, 2, 3}
  //
  vector<int> index;
  for (int i = 0; i < n; i++) {
    index.push_back(i);
  }

  // 都市 1 からスタートする経路の数は (N-1)! 通りである。
  // 移動時間の合計の計算量は O(N) である。
  // トータルの計算量は (N-1)! * N = O(N!) である。
  //
  // N <= 8 から最大の計算量は O(8!) = 40320 通りである。
  int ans = 0;
  do {
    int time = 0;
    for (int i = 0; i < n; i++) {
      //
      // 都市 i から都市 j への移動時間 T[i][j] を取得し
      // time に加算する。
      //
      // また T は要素数 n の vector コンテナであり、
      // 要素番号は 0-indexed のため 0 〜 n-1 である。
      //
      // 一方で i が取りうる都市番号は 0 〜 n-1 である。
      // i = n-1 の場合、i+1 = n となる。
      // T[n-1][n] にアクセスすると out_of_range エラーが発生する。
      //
      // ここで ((i+1) % n) で剰余を取得すると、
      // i+1 = n のケースのみ n % n = 0 となり、
      // T[n-1][0] の値を返す。
      //
      // T[n-1][0] は問題の「都市1に戻る経路」の移動時間に
      // 該当する。
      //
      time += T.at(index.at(i)).at(index.at((i + 1) % n));
    }
    if (time == k) {
      ans++;
    }
    //
    // next_permutation は [first, last) の範囲を対象に順列を生成する。
    //
    //   * [ は閉区間を意味する。
    //   * ) は開区間を意味する。
    //   * [a, b) は半開区間を意味する。
    //   * [first, last) は first <= x < last を表す。
    //
    // ### データ例
    // vector<int> v = {1, 2, 3, 4} の場合
    //
    // next_permutation(index.begin() + 1, index.end()) は
    //
    // index 番号 0 の要素 = 1 は順序が変わらず、
    // index 番号 1 から 3 の要素について、順列を生成する。
    // 生成される配列は以下となる。
    //
    //   * 1 2 3 4
    //   * 1 2 4 3
    //   * 1 3 2 4
    //   * 1 3 4 2
    //   * 1 4 2 3
    //   * 1 4 3 2
    //
    // 同様に next_permutation(index.begin(), index.end() - 1) は
    // index 番号 3 の要素 = 4 は順序が変わらず、
    // index 番号 0 から 2 の要素について、順列を生成する。
    // 生成される配列は以下となる。
    //
    //   * 1 2 3 4
    //   * 1 3 2 4
    //   * 2 1 3 4
    //   * 2 3 1 4
    //   * 3 1 2 4
    //   * 3 2 1 4
    //
  } while (next_permutation(index.begin() + 1, index.end()));

  cout << ans << endl;
  return 0;
}
