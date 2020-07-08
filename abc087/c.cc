#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool reachable(int &n, int x, int y) {
  if (x >= 0 && x < 2 && y >= 0 && y < n) {
    return true;
  }
  return false;
}

int search(vector<vector<int>> &board, int &n, int x, int y, int sum) {
  sum += board.at(x).at(y);
  // ベースケース
  if (x == 1 && y == n - 1) {
    return sum;
  }

  // 再帰ステップ
  // 縦軸に移動
  int p1 = 0;
  if (reachable(n, x + 1, y)) {
    p1 = search(board, n, x + 1, y, sum);
  }
  // 横軸に移動
  int p2 = 0;
  if (reachable(n, x, y + 1)) {
    p2 = search(board, n, x, y + 1, sum);
  }

  return max(p1, p2);
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> board(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board.at(i).at(j);
    }
  }

  int ans = search(board, n, 0, 0, 0);
  cout << ans << endl;
  return 0;
}
