#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  // a で選手ごとのレートを管理する。
  // 選手番号は 0-index である。
  //
  // ### 入力例1の場合
  //
  // a[0] = A1 = 1
  // a[1] = A2 = 4
  // a[2] = A3 = 2
  // a[3] = A4 = 5
  //
  vector<int> a((1 << n));
  for (int i = 0; i < (1 << n); i++) {
    cin >> a.at(i);
  }

  // remaining で残りの選手を管理する。
  // 選手番号は 0-indexed で管理する。
  vector<int> remaining(1 << n);
  iota(remaining.begin(), remaining.end(), 0);

  // ### n 回戦まで試合を繰り返すと、決勝戦になる。
  //
  // n = 2
  //   2**2 = 4
  //   2回
  // n = 3
  //   2**3 = 8
  //   3回
  //
  for (int i = 0; i < n; i++) {
    // 決勝戦の場合 = 残り2名の場合、準優勝者を求める。
    //
    // (注意) n = 1 の場合、1回戦の試合 = 決勝戦となる。
    // 試合を行う前に、準優勝者をすぐ求める必要がある。
    //
    if (remaining.size() == 2) {
      int left = remaining.at(0);
      int right = remaining.at(1);
      if (a.at(left) > a.at(right)) {
        cout << (right + 1) << endl;
      } else {
        cout << (left + 1) << endl;
      }
      return 0;
    }

    // n 回戦の試合を全て行う。
    //
    // 例: 入力例1の場合、n=2
    // 1回戦の試合は2回、2回戦の試合は1回行われる。
    vector<int> next_remaining;
    for (int j = 0; j < (int)remaining.size(); j = j + 2) {
      int left = remaining.at(j);
      int right = remaining.at(j + 1);
      if (a.at(left) > a.at(right)) {
        next_remaining.push_back(left);
      } else {
        next_remaining.push_back(right);
      }
    }
    remaining = next_remaining;
  }

  return 0;
}
