#include <bits/stdc++.h>
using namespace std;

bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int y, int x) {
  int h = board.size();
  int w = board[0].size();

  // 移動先が枠をはみ出している
  if (x <= -1 || x >= w || y <= -1 || y >= h) {
    return false;
  }
  // 移動先が堀
  if (board.at(y).at(x) == '#') {
    return false;
  }
  // 移動先が調査済み
  if (checked.at(y).at(x) == true) {
    return false;
  }
  // それ以外
  return true;
}

bool reachable(vector<string> &board, vector<vector<bool>> &checked, int y, int x) {
  checked.at(y).at(x) = true;

  // ベースケース
  if (board.at(y).at(x) == 'g') {
    return true;
  }

  bool result = false;
  // 上
  if (is_valid_move(board, checked, y - 1, x) && reachable(board, checked, y - 1, x)) {
    result = true;
  }
  // 右
  if (is_valid_move(board, checked, y, x + 1) && reachable(board, checked, y, x + 1)) {
    result = true;
  }
  // 下
  if (is_valid_move(board, checked, y + 1, x) && reachable(board, checked, y + 1, x)) {
    result = true;
  }
  // 左
  if (is_valid_move(board, checked, y, x - 1) && reachable(board, checked, y, x - 1)) {
    result = true;
  }
  return result;
}

int main() {
  int h, w;
  cin >> h >> w;

  // h = 10;
  // w = 10;

  vector<string> board(h);
  for (int i = 0; i < h; i++) {
    cin >> board.at(i);
  }
  vector<vector<bool>> checked(h, vector<bool>(w, false));

  // board[0] = "s.........";
  // board[1] = "#########.";
  // board[2] = "#.......#.";
  // board[3] = "#..####.#.";
  // board[4] = "##....#.#.";
  // board[5] = "#####.#.#.";
  // board[6] = "g.#.#.#.#.";
  // board[7] = "#.#.#.#.#.";
  // board[8] = "#.#.#.#.#.";
  // board[9] = "#.....#...";

  int start_x = -1;
  int start_y = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board.at(i).at(j) == 's') {
        start_y = i;
        start_x = j;
        break;
      }
    }
    if (start_x >= 0) {
      break;
    }
  }

  if (reachable(board, checked, start_y, start_x)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
