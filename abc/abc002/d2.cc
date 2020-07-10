#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; // <= 12
  int M; // <= (12 * 11) / 2 = 66
  cin >> N >> M;

  // 知り合い同士の組合せを true にする
  vector<vector<bool>> v(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-indexed
    v.at(x).at(y) = true;
    v.at(y).at(x) = true;
  }

  int ans = 1;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    // 検証対象の議員の組合せ
    vector<int> c;
    for (int i = 0; i < N; i++) {
      if (tmp & (1 << i)) {
        c.push_back(i);
      }
    }

    // 知り合いでない者同士の組合せがあるかどうか
    bool enabling = true;
    for (int i = 0; i < (int) c.size(); i++) {
      for (int j = i + 1; j < (int) c.size(); j++) {
        int x = c.at(i);
        int y = c.at(j);
        if (v.at(x).at(y) == false) {
          enabling = false;
        }
      }
    }

    if (enabling) {
      ans = max(ans, (int) c.size());
    }
  }

  cout << ans << endl;
  return 0;
}
