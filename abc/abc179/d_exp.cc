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

// くばるDP
ll dp_to_distribute(int &n, set<int> &s) {
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

// もらうDP
ll dp_to_receive(int &n, set<int> &s) {
  vector<ll> dp(n+1);
  dp.at(1) = 1;
  for (int i = 2; i <= n; i++) {
    for (auto si : s) {
      int source_cell = i-si;
      if (source_cell >= 1) {
        dp.at(i) += dp.at(source_cell);
        dp.at(i) %= MOD;
      }
    }
  }

  return dp.at(n);
}

// もらうDP + 累積和
ll dp_to_receive_with_cumulative_sum(int &n, int &k, vector<int> &l, vector<int> &r) {
  vector<ll> dp(n+1);
  vector<ll> dpsum(n+1);

  dp.at(1) = 1;
  dpsum.at(1) = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      // ### データ例
      // n = 5
      // i = 5
      // j = 1
      //   [l, r] = [[1, 1], [3, 4]]
      //
      // ### NOTE
      // dp[5] は5マス目への遷移パターン数である。
      //
      // j = 1 より [l, r] = [3, 4]
      // 3マス or 4マス移動して5マス目に到達するマス、
      // つまり、1マス目と2マス目から5マス目に移動できる。
      //
      //   i - r.at(j) = 5 - r[1] = 5 - 4 = 1
      //   i - l.at(j) = 5 - l[1] = 5 - 3 = 2
      //
      // dp[5] = 1マス目への遷移パターン数 + 2マス目への遷移パターン数、である。
      //
      //   1マス目への遷移パターン数 = 1通り（1）
      //   2マス目への遷移パターン数 = 1通り（1-->2）
      //
      // 1-->5 の1通りと 1-->2-->5 の1通りで合計2通り、dp[5] に加算される。
      // （これとは別に、1-->4-->5、1-->2-->3-->4-->5 のパターンも別のケースで加算される）
      //
      // ここで [l, r] = [1, 200000] のように、区間の要素数が 3 以上の場合、
      // 各要素の数を for 文でループして加算すると、計算量が O(n^2) になるため、
      // 累積和を使い、対象区間の dp[i] の総和を O(1) で求める。
      //
      // 累積和を dpsum で管理する。
      //
      //      dp :  1 2 3 4 5
      //   dpsum : 0 1 2 3 4 5
      //
      // 5マス目への遷移元区間は [1, 2] のため、
      // dpsum[2] - dpsum[0] = dp[1] + dp[2] - 0 より、区間の dp[i] の和を求める。
      //

      // li, ri はマス目 i の移動元区間 [i-r.at(j), i-l.at(j)] の累積和を取得する際の区切り位置である。
      // つまり dpsum の index である。
      int li = i - r.at(j) - 1;
      int ri = i - l.at(j);

      // ri < 0 の場合、li < 0 であり、累積和の index の範囲外となるため、スキップする。
      if (ri < 0) { continue; }
      // li < 0 かつ ri >= 0 の場合、例えば移動元区間が [-2, 1] のような場合、
      // li を 0 に変換し、[0, 1] の累積和を求める。
      //
      // これは区間 [Li, Ri] について、区間の全ての要素が移動元として成立しない場合に、
      // 移動元として成立する要素のみに累積和の区切り位置を限定して、累積和を求めている。
      li = max(li, 0);

      dp.at(i) = dp.at(i) + dpsum.at(ri) - dpsum.at(li);
      if (dp.at(i) < 0) {
        dp.at(i) += MOD;
      } else {
        dp.at(i) %= MOD;
      }
    }
    // dpsum[0] = 0
    // dpsum[1] = dpsum[0] + dp[1] = dp[1]
    // dpsum[2] = dpsum[1] + dp[2] = dp[1] + dp[2]
    dpsum.at(i) = dpsum.at(i - 1) + dp.at(i);
    dpsum.at(i) %= MOD;
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
  // set<int> s;
  // for (int i = 0; i < k; i++) {
  //   int l, r;
  //   cin >> l >> r;
  //   for (int i = l; i <= r; i++) {
  //     s.insert(i);
  //   }
  // }

  // l, r: 区間[l, r]
  vector<int> l(k);
  vector<int> r(k);
  for (int i = 0; i < k; i++) {
    cin >> l.at(i) >> r.at(i);
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

  // くばるDP
  // ll ans = dp_to_distribute(n, s);
  // cout << ans << endl;

  // もらうDP
  // ll ans = dp_to_receive(n, s);
  // cout << ans << endl;

  // もらうDP + 累積和
  ll ans = dp_to_receive_with_cumulative_sum(n, k, l, r);
  cout << ans << endl;

// #ifndef ONLINE_JUDGE
//   cout << "size: " << s.size() << '\n';
//   cout << "elem: ";
//   for (int value : s) { cout << value << " "; }
//   cout << '\n';
// #endif
  return 0;
}
