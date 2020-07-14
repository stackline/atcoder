#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;

  // H x W のグリッドデータ
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  // 二次元累積和
  vector<vector<int>> s(H + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      s.at(i + 1).at(j + 1) = s.at(i).at(j + 1) + s.at(i + 1).at(j) - s.at(i).at(j) + a.at(i).at(j);
    }
  }

#ifndef ONLINE_JUDGE
  cout << "# ONLINE_JUDGE" << endl;
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      cout << s.at(i).at(j) << " ";
    }
    cout << endl;
  }
  cout << "# ONLINE_JUDGE" << endl;
#endif

  // クエリ [x1, x2) x [y1, y2) の長方形区域の和
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << s.at(x2).at(y2) - s.at(x1).at(y2) - s.at(x2).at(y1) + s.at(x1).at(y1) << endl;
  }
  return 0;
}
