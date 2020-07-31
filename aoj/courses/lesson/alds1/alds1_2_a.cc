#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> bubble_sort(vector<int> &A, int N, int &num_of_exchanges) {
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
  int loop_counter = 0;
  while (existing) {
    existing = false;
    for (int j = N-1; j >= i+1; j--) {
      if (A.at(j) < A.at(j-1)) {
        int tmp1 = A.at(j);
        int tmp2 = A.at(j-1);
        A.at(j) = tmp2;
        A.at(j-1) = tmp1;

        num_of_exchanges++;
        existing = true;
      }
      loop_counter++;
    }
    i++;
  }

  return A;
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
