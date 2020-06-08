#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int W, H, N; // <= 100
  cin >> W >> H >> N;

  int x_begin = 0;
  int x_end = W;
  int y_begin = 0;
  int y_end = H;

  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;

    // 長方形の x < xi を満たす領域を黒く塗りつぶす
    if (a == 1) {
      x_begin = max(x_begin, x);
    // 長方形の x > xi を満たす領域を黒く塗りつぶす
    } else if (a == 2) {
      x_end = min(x_end, x);
    // 長方形の y < xi を満たす領域を黒く塗りつぶす
    } else if (a == 3) {
      y_begin = max(y_begin, y);
    // 長方形の y > xi を満たす領域を黒く塗りつぶす
    } else if (a == 4) {
      y_end = min(y_end, y);
    } else {
      cout << "error: a = " << a << endl;
      return 1;
    }
  }

  if (x_end > x_begin && y_end > y_begin) {
    cout << ((x_end - x_begin) * (y_end - y_begin)) << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
