#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  // 累積和を作る
  vector<int> sum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'A' && (i + 1) < N && S.at(i + 1) == 'C') {
      sum.at(i + 1) = sum.at(i) + 1;
    } else {
      sum.at(i + 1) = sum.at(i);
    }
  }

  // 解説PDFの「右端が1左に〜...」の箇所を参照する
  // * https://img.atcoder.jp/abc122/editorial.pdf
  //
  // (left, right) = (3, 7) の場合
  // * right は 7 - 1 で 6文字目までに "AC" を満たす "A" が存在する件数を数える
  // なぜなら 7 文字目が "A" で 8 文字目が "C" の場合、7文字目の "A" は終端を
  // 超えてしまうため。
  // * 同様に left も 3 - 1 で 2文字目までに "AC" を満たす "A" が存在する件数を数える
  // * これらより、3〜6文字目の中で "AC" を満たす "A" の件数を数える
  //
  // (left, right) = (2, 3) の場合
  // * right は 3 - 1 で 2文字目までの "AC" を満たす "A" が存在する件数を数える
  // * left も 2 - 1 で 1文字目に "AC" を満たす "A" が存在する件数を数える
  // * これらより 2〜2文字目の中で "AC" を満たす "A" の件数を数える
  // * つまり、2文字目が "AC" を満たす "A" であるかどうかを数える
  for (int i = 0; i < Q; i++) {
    int left, right;
    cin >> left >> right;
    cout << (sum.at(right - 1) - sum.at(left - 1)) << endl;
  }

  return 0;
}
