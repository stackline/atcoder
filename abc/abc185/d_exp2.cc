#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  // 最後に青色のマスを追加
  a.push_back(n + 1);

  // ### 入力例1の場合
  // 事前に、最後尾 (右端) に「青マス」を追加している
  //
  //   |青|白|青|白|白|青|
  //
  // カーソルを初期位置 1 にセット
  //
  //   |青|白|青|白|白|青|
  //    ^
  //
  // a[0] = 1 の時、1 - 1 = 0 より length = 0
  // カーソルを、青マスの次の 2 に移動させる
  //
  //   |青|白|青|白|白|青|
  //       ^
  //
  // a[1] = 3 の時、3 - 2 = 1 より length = 1
  // カーソルを青マスの次の 4 に移動させる
  //
  //   |青|白|青|白|白|青|
  //          ^
  //
  // (以下は仮の追加条件)
  // カーソルを 4 に移動した状態で、仮に a[2] = 4 という条件を追加する。
  //
  //   |青|白|青|青|白|青|
  //             ^
  //
  // a[2] = 4 の時、4 - 4 = 0 より length = 0
  // つまり、連続した白マスの数は 0 であるため、s に push_back しない。
  //
  int cursor = 1;
  vector<int> s;
  for (int i = 0; i < (int)a.size(); i++) {
    // 連続した白マスの数（青マスの位置 - 白マスの開始位置）
    int length = a.at(i) - cursor;
    if (length > 0) {
      s.push_back(length);
    }
    // カーソルを青マスの位置の次に移動させる
    cursor = a.at(i) + 1;
  }

  // 複数の「連続する白マス」のうち、もっとも短い「連続する白マス」を求める。
  int min_s = n;
  for (int i = 0; i < (int)s.size(); i++) {
    min_s = min(min_s, s.at(i));
  }

  int ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    //
    // 「分子の数」に「分母の数」を加算する場合、商が +1 される。
    // 「分子の数」に「分母の数 - 1」を加算する場合、以下の2パターンに分かれる。
    //
    //   * 分子の数 s.at(i) が min_s で割り切れる数の場合
    //     * 分子に (min_s - 1) を加算すると、それが余りの数となる。
    //     * (s.at(i) + (min_s - 1)) % min_s = min_s - 1
    //     * これより (s.at(i) + (min_s - 1)) / min_s の商は変わらない。
    //   * 分子の数 s.at(i) が min_s で割り切れない数の場合
    //     * s.at(i) % min_s = x とすると、x >= 1 である
    //     * (min_s - 1 + x) >= min_s である
    //     * 両辺を min_s で割ると(min_s - 1 + x) / min_s >= 1
    //     * これより (s.at(i) + (min_s - 1)) / min_s の商が 1 大きくなる。
    //
    // 上記の処理は、余りが0より大きい場合に切り上げする ceil と同じ。
    //
    ans += (s.at(i) + (min_s - 1)) / min_s;
  }

  cout << ans << endl;
  return 0;
}
