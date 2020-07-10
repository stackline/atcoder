#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  string board[h];
  for (int i = 0; i < h; i++) { cin >> board[i]; }

  // counter clockwise
  const int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
  const int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') { continue; }

      int num = 0;
      for (int d = 0; d < 8; d++) {
        // vertical
        const int ni = i + dy[d];
        // horizontal
        const int nj = j + dx[d];
        if (ni < 0 || ni >= h) { continue; }
        if (nj < 0 || nj >= w) { continue; }
        if (board[ni][nj] == '#') { num++; }
      }

      // Numeric representation of string '0' is 48.
      // '0' => 48
      // 48 + 1 = 49
      // 49 => '1'
      board[i][j] = '0' + num;
    }
  }

  for (int i = 0; i < h; i++) { cout << board[i] << endl; }
  return 0;
}
