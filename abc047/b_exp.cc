#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  vector<vector<int>> board(W, vector<int>(H, true));

  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;

    // 長方形の x < xi を満たす領域
    if (a == 1) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < H; j++) {
          board.at(i).at(j) = false;
        }
      }
    // 長方形の x > xi を満たす領域
    } else if (a == 2) {
      for (int i = x; i < W; i++) {
        for (int j = 0; j < H; j++) {
          board.at(i).at(j) = false;
        }
      }
    // 長方形の y < yi を満たす領域
    } else if (a == 3) {
      for (int i = 0; i < W; i++) {
        for (int j = 0; j < y; j++) {
          board.at(i).at(j) = false;
        }
      }
    // 長方形の y > yi を満たす領域
    } else if (a == 4) {
      for (int i = 0; i < W; i++) {
        for (int j = y; j < H; j++) {
          board.at(i).at(j) = false;
        }
      }
    } else {
      cout << "error" << endl;
      return 1;
    }
  }

  int ans = 0;
  for (auto v : board) {
    for (auto b : v) {
      if (b) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
