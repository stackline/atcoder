#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> time(N);
  vector<pair<int, int>> point(N);
  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;

    time.at(i) = t;
    point.at(i) = make_pair(x, y);
  }

  int current_t = 0;
  pair<int, int> current_p(0, 0);
  bool can = true;
  for (int i = 0; i < N; i++) {
    int next_t = time.at(i);
    pair<int, int> next_p = point.at(i);

    // 3 - 0 = 3
    int duration = next_t - current_t;
    // (1 - 0) + (2 - 0) = 3
    int distance = abs(next_p.first - current_p.first) + abs(next_p.second - current_p.second);

    // 問題あり（移動が間に合わない場合）
    if (distance > duration) {
      can = false;
      break;
    }
    // 問題あり（移動が間に合う、しかし時間ちょうどに座標点に存在できない場合）
    if (distance < duration) {
      // 目的地到着後、偶数時間残っていれば、調整が可能
      // 奇数時間の場合は調整不可
      if ((duration - distance) % 2 == 1) {
        can = false;
        break;
      }
    }

    // 移動先座標を起点とする
    current_t = next_t;
    current_p = next_p;
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
