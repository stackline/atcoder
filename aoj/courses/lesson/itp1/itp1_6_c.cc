#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // n件の情報
  int n;
  cin >> n;

  // 棟-->階-->フロア
  vector<vector<vector<int>>> a(4, vector<vector<int>>(3, vector<int>(10, 0)));

  // b棟
  // f階
  // r番目の部屋
  // v人が追加で入居（マイナスの場合は退去）
  for (int i = 0; i < n; i++) {
    int b, f, r, v;
    cin >> b >> f >> r >> v;

    // 0-indexedにする
    b--;
    f--;
    r--;

    a.at(b).at(f).at(r) += v;
  }

  // 棟
  for (int b = 0; b < 4; b++) {
    // 階
    for (int f = 0; f < 3; f++) {
      // 部屋番号
      for (int r = 0; r < 10; r++) {
        cout << " " << a.at(b).at(f).at(r);
      }
      cout << endl;
    }

    // 最後は出力しない
    if (b != 3) {
      for (int i = 0; i < 20; i++) { cout << "#"; }
      cout << endl;
    }
  }

  return 0;
}
