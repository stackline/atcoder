#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(112 * |S|) = O(|S|)
bool solve(string s) {
  // 1桁
  if (s.size() == 1) {
    return (s == "8");
  }
  // 2桁
  if (s.size() == 2) {
    if (stoi(s) % 8 == 0) {
      return true;
    }
    swap(s.at(0), s.at(1));
    if (stoi(s) % 8 == 0) {
      return true;
    }
    return false;
  }
  // 3桁以上
  //
  // 標準入力から与えられた数字列について、
  // 各数字の数を cnt でカウントする。
  //
  //   ### 入力例1 : 1234 の場合
  //   cnt['1' - '0'] --> cnt[1] = 1
  //   cnt['2' - '0'] --> cnt[2] = 1
  //   cnt['3' - '0'] --> cnt[3] = 1
  //   cnt['4' - '0'] --> cnt[4] = 1
  //
  // cnt をコピーした cnt2 を作る。
  // 3桁の8の倍数の数字について、以下の作業を繰り返す。
  //
  //   候補の数字列について、各数字の登場回数分、cnt2 から引く。
  //
  //   ### i = 112 の場合
  //   cnt2[0] =  0
  //   cnt2[1] = -1
  //   cnt2[2] =  0
  //   cnt2[3] =  1
  //   cnt2[4] =  1
  //
  //   1 の数が不足するため、112 は作成できない。
  //
  //   ### i = 120 の場合
  //   cnt2[0] = -1
  //   cnt2[1] =  0
  //   cnt2[2] =  0
  //   cnt2[3] =  1
  //   cnt2[4] =  1
  //
  //   標準入力から与えられる数字列は 1〜9 の数字のみからなる。
  //   そのため cnt[0] のカウントは 0 である。
  //   この状態で 0 を含む数字を作成しようとすると、
  //   cnt2[0] のカウントがマイナスとなり、作成できないと判定する。
  //
  //   ### i = 432 の場合
  //   cnt2[0] =  0
  //   cnt2[1] =  1
  //   cnt2[2] =  0
  //   cnt2[3] =  0
  //   cnt2[4] =  0
  //
  //   カウントがマイナスになる数字が存在しない。
  //   つまり cnt2 の各要素の値が全て 0 以上である。
  //   そのため 432 は標準入力で与えられた数字列 1234 から
  //   作成可能な数字である。
  //
  vector<int> cnt(10);
  for (char c : s) {
    cnt.at(c - '0')++;
  }
  // 112: 8の倍数の数字の内、3桁で0を含まない最小の値
  for (int i = 112; i < 1000; i = i + 8) {
    auto cnt2 = cnt;
    for (char c : to_string(i)) {
      cnt2.at(c - '0')--;
    }
    // 全てのカウンターが0以上かどうか
    if (all_of(cnt2.begin(), cnt2.end(), [](int n) { return n >= 0; })) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  // ### 制約 1 <= |S| <= 2 * 10**5 について
  //
  // * 有限集合と濃度について
  //   * 集合 S が n 個の要素を持つとき、集合 S を有限集合と呼ぶ。
  //     * 要素数が数えられること
  //   * 要素数 n を、有限集合 S の濃度と呼ぶ。
  //   * 有限集合 S の濃度を |S| と表記する。
  //   * ref. https://home.hiroshima-u.ac.jp/fujita/Class/Kisoron/set.pdf
  // * 数字列 S について
  //   * string 型で標準入力から受け取る。
  //   * string.size() で要素数が数えられる。
  //     * 文字列 S は文字 (char) の有限集合である。
  //   * 制約 |S| <= 2 * 10**5
  //     * 有限集合 S の濃度 = 要素数は 2 * 10**5 以下である。
  // * 文字列 S の長さは 2 * 10**5 以下である。
  string s;
  cin >> s;
  cout << (solve(s) ? "Yes" : "No") << endl;
  return 0;
}
