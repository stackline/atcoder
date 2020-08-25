#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s = "1234";

  // * 1 << 3
  //   * 3ビット、左にシフトさせる
  //   * 0001 は 1000 となる
  //   * 2進数の 1000 を10進数に変換すると 8 となる
  //   * そのため、2進数で表すと 000 〜 111 の 8 通りとなる
  //
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    // 初期化リストで囲って、char型をstring型にキャスト
    string formula = { s.at(0) };

    for (int i = 0; i < 3; i++) {
      // * tmp = 0 の場合
      //   * 000 & 001 => 000
      //   * 000 & 010 => 000
      //   * 000 & 100 => 000
      // * tmp = 1 の場合
      //   * 001 & 001 => 001
      //   * 001 & 010 => 000
      //   * 001 & 100 => 000
      // * tmp = 7 の場合
      //   * 111 & 001 => 001
      //   * 111 & 010 => 010
      //   * 111 & 100 => 100
      //
      // * 対象となる2進数について、i桁目が1かどうかを確認する
      string num_str = { s.at(i + 1) };
      if (tmp & (1 << i)) {
        formula += "+" + num_str;
      } else {
        formula += '-' + num_str;
      }
    }

    cout << tmp << " : " << bitset<3>(tmp) << " : " << formula << endl;
  }

  return 0;
}
