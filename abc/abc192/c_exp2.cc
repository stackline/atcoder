#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n) {
  vector<int> v(20, 0);
  while (n) {
    int rest = n % 10;
    v.at(rest)++;
    n = n / 10;
  }

  int g1 = 0;
  int g2 = 0;
  // 引数で与えられた整数の各桁の数字を確認し、
  // 1〜9 の数字の数をそれぞれカウントする。
  //
  // ### 入力例1 の場合
  //
  // n = 314
  //
  // 配列は以下となる。
  //
  //   v[1] = 1
  //   v[3] = 1
  //   v[4] = 1
  //
  // 1〜9 の値について、降順で各数字の数を取得し、10倍する。
  // n = 314 の場合
  //
  //   (0 * 10)  + 4 = 4
  //   (4 * 10)  + 3 = 43
  //   (43 * 10) + 1 = 431
  //
  // こちらは問題文の g1(x) の処理と同じである。
  //
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < v.at(i); j++) {
      g1 = g1 * 10 + i;
    }
  }
  // こちらは g2(x) の処理と同じである。
  // 事前にカウントした 1〜9 の数について、昇順で各数字の数を取得し、10倍していく。
  //
  // n = 314 の場合
  //
  //   (0 * 10)  + 1 = 1
  //   (1 * 10)  + 3 = 13
  //   (13 * 10) + 4 = 134
  //
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j < v.at(i); j++) {
      g2 = g2 * 10 + i;
    }
  }
  return g1 - g2;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    n = f(n);
  }
  cout << n << endl;
  return 0;
}
