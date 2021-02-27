#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(string s, ll last_one) {
  vector<ll> card(10, 0);
  // 先頭4枚
  for (ll i = 0; i < 4; i++) {
    ll si = s.at(i) - '0';
    card.at(si)++;
  }
  // ラスト1枚
  card.at(last_one)++;
  // 点数計算
  ll score = 0;
  for (ll i = 1; i <= 9; i++) {
    ll exp = card.at(i);
    ll num = i;
    for (ll i = 0; i < exp; i++) {
      num = num * 10;
    }
    score += num;
  }
  return score;
}

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  ll k;
  cin >> k;

  string s, t;
  cin >> s >> t;

  // トランプの残りを管理
  // 1-indexed、0 番は使わない
  vector<ll> card(10, k);

  // 既存のトランプ8枚を引く
  for (ll i = 0; i < 4; i++) {
    ll si = s.at(i) - '0';
    card.at(si)--;
    ll ti = t.at(i) - '0';
    card.at(ti)--;
  }

  // for (int i = 1; i <= 9; i++) {
  //   cout << i << ", " << card.at(i) << endl;
  // }

  // 高橋くんが1〜9、青木くんが1〜9で全探索する
  ll takahashi_win_pattern = 0;
  ll total_pattern = 0;

  for (ll i = 1; i <= 9; i++) {
    for (ll j = 1; j <= 9; j++) {
      vector<ll> rest = card;
      ll rest_i = rest.at(i);
      rest.at(i)--;

      ll rest_j = rest.at(j);
      rest.at(j)--;

      // cout << "i: " << i << ", j; " << j << ", rest_i: " << rest_i
      //      << ", rest_j; " << rest_j << endl;
      // cout << "rest.at(i): " << rest.at(i) << ", rest.at(j); " << rest.at(j)
      //      << endl;

      // カードが足りない場合、成立しないのでスキップ
      if (rest.at(i) < 0 || rest.at(j) < 0) {
        continue;
      }
      // 点数を計算する
      ll takahashi_score = calc(s, i);
      ll aoki_score = calc(t, j);
      // 全パターンと高橋くんが勝つパターンを記録する
      ll pattern_cnt = rest_i * rest_j;
      // cout << "total_pattern:       " << total_pattern << endl;
      // cout << "takashi_win_pattern: " << takahashi_win_pattern << endl;
      total_pattern += pattern_cnt;
      if (takahashi_score > aoki_score) {
        takahashi_win_pattern += pattern_cnt;
      }
    }
  }

  // cout << takahashi_win_pattern << endl;
  // cout << total_pattern << endl;

  double ans = (double)takahashi_win_pattern / total_pattern;
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}
