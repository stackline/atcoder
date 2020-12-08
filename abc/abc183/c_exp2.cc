#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, k;
  cin >> n >> k;

  vector<vector<int>> t(8, vector<int>(8));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t.at(i).at(j);
    }
  }

  // 都市番号は 0-indexed とする。
  // 都市番号が 1 〜 n-1 の都市について、全ての順列を試す。
  //
  // p の要素番号は 0 〜 n-2 となる。
  vector<int> p;
  for (int i = 1; i < n; i++) {
    p.push_back(i);
  }

  int ans = 0;
  do {
    // 都市 0 から都市 p[0] までの移動距離
    int total = t.at(0).at(p.at(0));
    // 都市 p[0] から都市 p[1] への移動時間
    // ...
    // 都市 p[n-3] から都市 p[n-2] への移動時間
    //
    // 上記の移動時間をそれぞれ加算する。
    for (int i = 0; i < n - 2; i++) {
      int from = p.at(i);
      int to = p.at(i + 1);
      total += t.at(from).at(to);
    }
    // 都市 p[n-2] から都市 0 への移動時間
    total += t.at(p.at(n - 2)).at(0);

    if (total == k) {
      ans++;
    }
    // ### next_permutation
    //
    // 今回の場合、vector コンテナクラスのメンバ変数である
    // vector<int>::iterator 型の値を引数に取る。
    //
    // [first, last) で指定した区間の要素を順列に並べ替える。
    // そのため、next_permutation の第一引数を p.begin() + 1
    // とする場合、0 番目の要素は並べ替えられない。
    //
    // また、next_permutation は次の順列を生成することができる場合、
    // true、生成できない場合は false を返す。
    //
    // next_permutation は辞書順に並び替えて順列を生成する。
    // そのため、以下の例では {1, 2, 3}, {1, 3, 2} の組み合わせは生成されない。
    // {2, 1, 3} の次は、辞書順で {2, 3, 1} が生成される。
    //
    //   vector<int> v = {2, 1, 3};
    //   do {
    //     ...
    //   } while (next_permutation(v.begin(), v.end()));
    //
    // 次の順列が生成できなくなった時点で vector コンテナは
    // 辞書順の最後の並びとなっている。
    //
    //   上記 v = {2, 1, 3} の例では、
    //   v = {3, 2, 1} に並び替えられている。
    //
    // おそらく、順列が生成できず false を返すタイミングで、
    // vector コンテナの要素を reverse(v.begin(), v.end()) で
    // 辞書順の最初の並びにしている。
    //
    //   上記例では v = {3, 2, 1} を
    //   v = {1, 2, 3} にしている。
    //
    // これより do-while の実行前に vector の要素を予め
    // sort している場合は、do-while 終了後に vector の値が
    // 元に戻っている（あるいは、do-while ブロック内でのみ
    // 順番が変更されている）ように見える。
    //
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
  return 0;
}
