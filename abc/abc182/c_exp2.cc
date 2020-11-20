#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;
  int n = s.size();

  // 3で割った余りの数を集計する
  vector<int> cnt(3);
  for (int i = 0; i < n; i++) {
    int remainder = (s.at(i) - '0') % 3;
    cnt.at(remainder)++;
  }

  // 現在の余りの数の合計
  int x = 0;
  for (int i = 0; i < 3; i++) {
    x += cnt.at(i) * i;
  }

  // 適当に大きな値
  const int INF = 1e8;
  int ans = INF;

  // 「3で割った余りが1の数」と「3で割った余りが2の数」を
  // それぞれ 0〜2 個消すパターンを全探索する。
  //
  //   3パターン x 3パターン = 9パターン
  //
  // 例えば、標準入力から与えられた値が 3 の倍数の場合、
  // 「3で割った余りが1の数」と「3で割った余りが2の数」を
  // 1件も消さないパターンとして、探索できる。
  //
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // 「3で割った余りが1の数」を登場した件数以上に
      // 削除しようとした場合はスキップする。
      if (i > cnt.at(1)) {
        continue;
      }
      // 「3で割った余りが2の数」の場合も同様。
      if (j > cnt.at(2)) {
        continue;
      }
      // 削除する件数と桁数が同じ場合はスキップ。
      // 制約として、全ての桁を削除することはできず、
      // 1桁以上残す必要がある。
      if ((i + j) == n) {
        continue;
      }
      // 削除後の数字が3の倍数の場合 (各桁の数の和が3の倍数の場合)
      // 答えを更新する。
      int nx = x;
      nx -= i * 1;
      nx -= j * 2;
      if (nx % 3 == 0) {
        ans = min(ans, (i + j));
      }
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
