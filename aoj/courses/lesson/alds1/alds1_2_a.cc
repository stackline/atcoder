#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量
//   N-1 * N-2 * ... * 2 * 1
// = (N-1 + 1) * (N-1 / 2)
// = (N) * (N-1 / 2)
// = (N**2 - N) / 2
// = O(N**2)

// MEMO:
// 螺旋本の回答例では、関数が引数として配列を受け取る。
// 配列は std::vector や std::array ではなく、int a[] で表す配列である。
// 以下の2つのシグネチャは、配列の先頭要素へのポインタ値が渡されている。
// そのため、関数内で配列の要素の値を変更すると、呼び出し元の変数から参照する値も変更となる。
//
//   // 関数
//   // void func(int *A) {} と同じ
//   void func(int A[]) {}
//
//   // 呼び出し元
//   int A[100]
//   func(A);
//
void bubble_sort(vector<int> &A, int N, int &num_of_exchanges) {
  // # while ループ1回目
  // * 5 3 2 4 1
  //   * 1 < 4 のため、4 1 をひっくり返す
  // * 5 3 2 1 4
  //   * 1 < 2 のため、2 1 をひっくり返す
  // * 5 3 1 2 4
  //   * 1 < 3 のため、3 1 をひっくり返す
  // * 5 1 3 2 4
  //   * 1 < 5 のため、5 1 をひっくり返す
  // * 1 5 3 2 4
  //
  // # while ループ2回目
  // * 1 5 2 3 4
  //   * 4 > 3 のため、3 4 はひっくり返さない
  // * 1 5 2 3 4
  //   * 3 > 2 のため、2 3 はひっくり返さない
  // * 1 5 2 3 4
  //   * 2 < 5 のため、5 2 はひっくり返す
  // * 1 2 5 3 4
  //   * 2 > 1 のため、1 2 はひっくり返さない
  //
  // # while ループ3回目 (省略)
  // * 1 2 3 5 4
  //
  // # while ループ4回目 (省略)
  // * 1 2 3 4 5
  //
  // 最終的に5個の要素に「逆の隣接要素」が存在しなくなる。
  // その結果、for ループで existing = true が代入されなくなる。
  // existing = false のため while ループが終了する。
  //
  bool existing = true;
  int i = 0; // 未ソートの部分の先頭を指すループ変数
  while (existing) {
    existing = false;
    for (int j = N-1; j >= i+1; j--) {
      if (A.at(j) < A.at(j-1)) {
        swap(A.at(j), A.at(j-1));
        num_of_exchanges++;
        existing = true;
      }
    }
    i++;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  int num_of_exchanges = 0;
  bubble_sort(v, n, num_of_exchanges);

  for (int i = 0; i < n; i++) {
    cout << v.at(i);
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << num_of_exchanges << endl;

  return 0;
}
