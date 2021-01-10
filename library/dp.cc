#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ref. https://www.slideshare.net/iwiwi/ss-3578511
//
// 二分探索
//
// p[i].first  重さ
// p[i].second 価値
// i 品物の番号
// u ナップサックにあとどれくらい入るか
//
int search(vector<pair<int, int>> &p, int i, int u) {
  // ベースケース
  int n = p.size();
  if (i == n) {
    return 0;
  }

  // 再帰ステップ
  int weight = p.at(i).first;
  int value = p.at(i).second;
  // 品物の重さがナップサックの許容量を超えているため、品物は入らない
  if (weight > u) {
    return search(p, i + 1, u);
    // 品物の重さがナップサックの許容量を超えていないため、品物は入る
  } else {
    int res1 = search(p, i + 1, u);
    int res2 = search(p, i + 1, u - weight) + value;
    return max(res1, res2);
  }
}

// メモ探索（再帰関数のメモ化）
//
// 入力例
//   u = 10
//
//   品物番号 0 1 2 3
//   ----------------
//   重さ     2 2 3 2
//   価値     3 2 4 2
//
// 以下の経路で f(2,8) のメモが使われる。
//
// * f(0,10) -- 0 を入れない -- f(1,10) -- 1 を入れる -- f(2,8)
//   * 1回目の f(2,8) はキャッシュがないため、計算する。
//   * 以下の計算結果と f(2,8) = max(f(3,4), f(3,8)) から、f(2,8) は 6 を返す。合わせてキャッシュする。
//   * f(2,8) ------ 2 を入れる -- f(3,4) ----- 3 を入れる ---- f(4,2) ==> (+6)
//            |                          |
//            |                          +---- 3 を入れない -- f(4,4) ==> (+4)
//            |
//            +---- 2 を入れない -- f(3,8) --- 3 を入れる ---- f(4,6) ==> (+2)
//                                         |
//                                         +-- 3 を入れない -- f(4,8) ==> (+0)
// * f(0,10) -- 0 を入れる -- f(1,8) -- 1 を入れない -- f(2,8)
//   * 2回目の f(2,8) はキャッシュがあるため、キャッシュの +6 を返す。
//   * キャッシュを利用することで、関数 f の呼び出しを6回削減する。
//
int memoize(vector<vector<bool>> &done, vector<vector<int>> &memo,
            vector<pair<int, int>> &p, int i, int u) {
  //////////////////////////////////////
  // ベースケース
  int n = p.size();
  if (i == n) {
    return 0;
  }
  //////////////////////////////////////

  // 再帰ステップ
  // 計算済みの場合は計算結果を返す
  if (done.at(i).at(u)) {
    cout << "memo exists" << endl;
    cout << "i, u : " << i << ", " << u << endl;
    cout << "memo.at(i).at(u) : " << memo.at(i).at(u) << endl;
    return memo.at(i).at(u);
  }

  int res;
  //////////////////////////////////////
  int weight = p.at(i).first;
  int value = p.at(i).second;
  // 品物の重さがナップサックの許容量を超えているため、品物は入らない
  if (weight > u) {
    res = memoize(done, memo, p, i + 1, u);
    // 品物の重さがナップサックの許容量を超えていないため、品物は入る
  } else {
    int res1 = memoize(done, memo, p, i + 1, u);
    int res2 = memoize(done, memo, p, i + 1, u - weight) + value;
    res = max(res1, res2);
  }
  //////////////////////////////////////

  done.at(i).at(u) = true; // 計算したことを記録する
  memo.at(i).at(u) = res;  // 値を記憶する
  return res;
}

// 動的計画法（漸化式 + ループ）
//
// search(i, u) = max(search(i+1, u), search(i+1, u-w,) + v)
//
int do_dp(vector<pair<int, int>> &p, int n, int u) {
  vector<vector<int>> dp(n + 1, vector<int>(u + 1, 0));
  // 境界条件
  for (int i = 0; i < u + 1; i++) {
    dp.at(n).at(i) = 0;
  }

  // n : 商品
  for (int i = n - 1; i >= 0; i--) {
    int weight = p.at(i).first;
    int value = p.at(i).second;

    // u : ナップサックに詰める重さ
    for (int j = 0; j < u + 1; j++) {
      // 商品 i をナップサックに入れられない
      if (weight > j) {
        dp.at(i).at(j) = dp.at(i + 1).at(j);
        // 商品 i をナップサックに入れられる
      } else {
        // 入れない
        int res1 = dp.at(i + 1).at(j);
        // 入れる
        // 商品 i を入れる場合、商品 i+1 の戻り地は f(i+1, u-weight) になる。
        int res2 = value + dp.at(i + 1).at(j - weight);
        dp.at(i).at(j) = max(res1, res2);
      }
    }
  }

#ifdef ONLINE_JUDGE
  cout << "-----------------------------------" << '\n';
  cout << "  ";
  for (int j = 0; j < u + 1; j++) {
    cout << (j >= 10 ? " " : "  ");
    cout << j;
  }
  cout << '\n';
  cout << "-----------------------------------" << '\n';
  for (int i = 0; i < n + 1; i++) {
    cout << i << " ";
    for (int j = 0; j < u + 1; j++) {
      cout << (dp.at(i).at(j) >= 10 ? " " : "  ");
      cout << dp.at(i).at(j);
    }
    cout << '\n';
  }
  cout << "-----------------------------------" << '\n';
#endif

  return dp.at(0).at(u);
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  // 入力例
  int n = 4;
  int u = 10;
  vector<pair<int, int>> p(n);
  p.at(0) = make_pair(2, 3);
  p.at(1) = make_pair(2, 2);
  p.at(2) = make_pair(3, 4);
  p.at(3) = make_pair(2, 2);

  // 二分探索
  cout << "### binary search" << endl;
  cout << search(p, 0, u) << endl;

  // メモ探索（再帰関数のメモ化）
  // すでに計算したかどうか
  vector<vector<bool>> done(n, vector<bool>(u + 1, false));
  // 計算した値の記録
  vector<vector<int>> memo(n, vector<int>(u + 1, 0));
  cout << endl;
  cout << "### memoize" << endl;
  cout << memoize(done, memo, p, 0, u) << endl;

  // 動的計画法（漸化式 + ループ）
  cout << endl;
  cout << "### recurrence formula" << endl;
  cout << do_dp(p, n, u) << endl;
  return 0;
}
