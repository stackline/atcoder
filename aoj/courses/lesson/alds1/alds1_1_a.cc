#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void cout_vector(vector<int> a) {
  int a_size = (int)a.size();
  for (int i = 0; i < a_size; i++) {
    cout << a.at(i);
    if (i < a_size - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

// 配列の対象のインデックス番号 (>=1) の値 x について、
// より若いインデックス番号の値 y と比較する。
//
// x < y を満たす場合、y の値をインデックス番号 +1 にコピーする。
// これを繰り返して、値を右に移動していくイメージ。
//
// インデックス番号 0 に到達する or x > y を満たす場合、
// その時点で左に自分自身 x より低い値がないため、移動を止めて、そこに x をセットする
//
// 例: [1, 3, 4, 2] という配列の場合
//
// step1: 1, 3, 4, 2 // 何もしない
// step2: 1, 3, 4, 4 // 2 < 4 のため、4 を右に代入して移動
// step3: 1, 3, 3, 4 // 2 < 3 のため、3 を右に代入して移動
// step4: 1, 2, 3, 4 // 2 > 1 のため、代入して移動はやらない
//                   // 代わりに移動して空いた穴に 2 をセットする
//
vector<int> insertion_sort(vector<int> a, int n) {
  // i = 1
  //   A[1]の2をA[0]の5と比較する
  //     A[1] < A[0] のため、A[1] = A[0] (2)
  //   A[0]に元のA[1]の値を代入する
  // i = 2
  //   A[2]の4をA[1]の5と比較する
  //     A[2] < A[1] のため、A[2] = A[1] (5)
  //   A[1]の5をA[0]の2と比較する
  //     A[1] > A[0] のため、代入はしない
  //   A[1]に元のA[2]の値を代入する
  for (int i = 1; i < n; i++) {
    int v = a.at(i);
    int j = i - 1;
    while (j >= 0 && a.at(j) > v) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = v;

    cout_vector(a);
  }

  return a;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  cout_vector(a);
  vector<int> sorted = insertion_sort(a, n);
  return 0;
}
