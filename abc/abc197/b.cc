#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w, x, y;
  cin >> h >> w >> x >> y;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s.at(i);
  }

  x--;
  y--;

  int dx;
  int dy;
  int cnt = 0;

  // 上
  dx = x;
  while (1) {
    if (dx == 0) {
      break;
    }
    dx--;
    if (s.at(dx).at(y) == '.') {
      cnt++;
    } else {
      break;
    }
  }
  // cout << cnt << endl;
  // 下
  dx = x;
  while (1) {
    if (dx == h - 1) {
      break;
    }
    dx++;
    if (s.at(dx).at(y) == '.') {
      cnt++;
    } else {
      break;
    }
  }
  // cout << cnt << endl;
  // 左
  dy = y;
  while (1) {
    if (dy == 0) {
      break;
    }
    dy--;
    if (s.at(x).at(dy) == '.') {
      cnt++;
    } else {
      break;
    }
  }
  // cout << cnt << endl;
  // 右
  dy = y;
  while (1) {
    if (dy == w - 1) {
      break;
    }
    dy++;
    if (s.at(x).at(dy) == '.') {
      cnt++;
    } else {
      break;
    }
  }
  // cout << cnt << endl;

  // 自分自身を追加
  cout << (cnt + 1) << endl;
  return 0;
}
