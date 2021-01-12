#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 空間計算量 O(HW)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w;
  cin >> h >> w;

  // C++17 の場合、テンプレート引数を省略できるパターンがある。
  // コンパイラが引数を推定してくれる。
  //
  // vector<vector<int>> a(h, vector<int>(w));
  vector a(h, vector<int>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a.at(i).at(j);
    }
  }

  int m = 100;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      m = min(m, a.at(i).at(j));
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans += a.at(i).at(j) - m;
    }
  }

  cout << ans << endl;
  return 0;
}
