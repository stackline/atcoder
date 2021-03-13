#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll score(string s) {
  // cnt[0] = 0
  // cnt[1] = 1
  // cnt[2] = 2
  // ...
  // と、Ci = 0 の時の点数をセットする。
  vector<ll> cnt(10);
  iota(cnt.begin(), cnt.end(), 0);

  // 番号の登場回数分、10倍する
  for (char c : s) {
    int n = c - '0';
    cnt.at(n) *= 10;
  }

  // 範囲を集計する
  return accumulate(cnt.begin(), cnt.end(), 0);
}

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll k;
  string s, t;
  cin >> k >> s >> t;

  // カードの枚数をカウント
  // 1-indexed で、添字 1 〜 9 を利用する。
  vector<ll> cnt(10, k);
  for (char c : s + t) {
    if (c == '#') {
      continue;
    }
    cnt.at(c - '0')--;
  }

  // 高橋くん、青木くんに5枚目を配るための、配り方の全パターン
  ll all_patterns = (9 * k - 8) * (9 * k - 8 - 1);
  // 高橋くんが勝つパターン
  ll takahashi_win = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      // 5文字目を更新する
      s.back() = '0' + i;
      t.back() = '0' + j;
      // 点数計算する
      ll score_s = score(s);
      ll score_t = score(t);
      // 高橋くんが勝たない場合はスキップ
      if (score_s <= score_t) {
        continue;
      }

      // 高橋くんが勝つ場合、(i,j) の取りうるパターン数を計算し、加算する。
      // なお、カードの枚数が足りない場合は、cnt.at(x) = 0 となり、
      // カウントされない。
      //
      //   ・例
      //     ・3 のカードの残り枚数が1枚である。
      // 　  ・(i,j) = (3,3) の場合 (cnt.at(3) - 1) = 0 となる。
      //     ・高橋くんの勝ちパターン数に加算する数も 0 となる。
      //
      if (i == j) {
        // 2名に配るカードの番号が同じ場合
        takahashi_win += cnt.at(i) * (cnt.at(j) - 1);
      } else {
        // 2名に配るカードの番号が異なる場合
        takahashi_win += cnt.at(i) * cnt.at(j);
      }
    }
  }

  cout << (double)takahashi_win / all_patterns << endl;
  return 0;
}
