#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

// 全探索
//
// s: 区間の和集合
// n: 最大のマス番号
// current: 現在のマス番号
ll full_search(set<int> &s, int &n, int current) {
  // ベースケース（ゴールに到着）
  if (current == n) {
    return 1;
  }

  // 再起ステップ
  ll cnt = 0;
  for (auto i : s) {
    // nマス以内であれば、探索を進める。
    // ゴールに到達した移動方法があれば、cnt を +1 する。
    if ((current+i <= n)) {
      cnt = cnt + full_search(s, n, current + i);
    }
  }

  return cnt;
}

// メモ探索
//
// ・入力例1〜4は処理できる。
// ・提出すると TLE が発生する。
// ・極端に大きな入力例を指定すると Segmentation fault が発生する。
// 　・n=10000、s=[1, 200000] の場合、時間がかかるけど正常終了する。
// 　・n=100000、s=[1, 200000] の場合、Segmentation fault が発生する。
// ・以下のコマンドでデバッグを行い、current=70000 ぐらいでエラーしていることを確認した。
// 　・ループしすぎなのかもしれない。
//
// ```
// $ g++-9 -g -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -o a.out d.cc
// $ lldb -f a.out
// ```
//
ll memoize(vector<bool> &done, vector<int> &memo, set<int> &s, int &n, int current) {
  // ベースケース（ゴールに到着）
  if (current == n) {
    return 1;
  }

  // 再起ステップ
  // ---------- memoize begin ----------
  if (done.at(current)) {
    return memo.at(current);
  }
  // ---------- memoize end   ----------

  ll cnt = 0;
  for (int i : s) {
    // nマス以内であれば、探索を進める。
    // ゴールに到達した移動方法があれば、cnt を +1 する。
    if ((current+i <= n)) {
      cnt = cnt + memoize(done, memo, s, n, current + i);
      cnt = cnt % MOD;
    }
  }

  // ---------- memoize begin ----------
  // 計算したことを記録する。
  done.at(current) = true;
  // 特定のマス current に到達した後、
  // current からゴールに到着するパターン数 cnt を記録する。
  // 次以降の探索では、current マスに到着した後の探索を行わず、
  // メモ化した結果を使うことで、探索回数を減らす。
  memo.at(current) = cnt;
  // ---------- memoize end   ----------

  return cnt;
}

// DP
ll do_dp(int &n, set<int> &s) {
  vector<ll> dp(n+1, 0);
  dp.at(1) = 1;
  for (int i = 1; i <= n; ++i) {
    for (auto a : s) {
      if (i+a <= n) {
        dp.at(i+a) += dp.at(i);
        dp.at(i+a) = dp.at(i+a) % MOD;
      }
    }
  }

  return dp.at(n);
}

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  // n: マス目の数
  // k: 区間の数
  int n, k;
  cin >> n >> k;

  // l, r: 区間[l, r]
  // s: 区間の和集合
  set<int> s;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      s.insert(i);
    }
  }

  // 全探索
  // ll ans = full_search(s, n, 1);
  // cout << ans << endl;

  // メモ探索
  // マス目を 1-indexed で取り扱っているので、要素数を n+1 している。
  // vector<bool> done(n+1, false);
  // vector<int> memo(n+1, 0);
  // ll ans = memoize(done, memo, s, n , 1);
  // cout << ans << endl;

  // DP
  ll ans = do_dp(n, s);
  cout << ans << endl;

#ifndef ONLINE_JUDGE
  cout << "size: " << s.size() << '\n';
  cout << "elem: ";
  for (int value : s) { cout << value << " "; }
  cout << '\n';
#endif
  return 0;
}
