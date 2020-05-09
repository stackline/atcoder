#include <bits/stdc++.h>
using namespace std;

bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int y, int x) {
  int n = board.size();

  // 移動先がマス目の外
  if (x <= -1 || x >= n || y <= -1 || y >= n) {
    return false;
  }
  // 移動先が海
  if (board.at(y).at(x) == 'x') {
    return false;
  }
  // 移動先が調査済み
  if (checked.at(y).at(x) == true) {
    return false;
  }
  // それ以外
  return true;
}

void fill_island(vector<string> &board, vector<vector<bool>> &checked, int y, int x) {
  checked.at(y).at(x) = true;

  if (is_valid_move(board, checked, y - 1, x)) {
    fill_island(board, checked, y - 1, x);
  }
  if (is_valid_move(board, checked, y, x + 1)) {
    fill_island(board, checked, y, x + 1);
  }
  if (is_valid_move(board, checked, y + 1, x)) {
    fill_island(board, checked, y + 1, x);
  }
  if (is_valid_move(board, checked, y, x - 1)) {
    fill_island(board, checked, y, x - 1);
  }
}

bool is_one_island(vector<string> &board) {
  vector<vector<bool>> checked(10, vector<bool>(10, false));

  int y = -1;
  int x = -1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board.at(i).at(j) == 'o') {
        y = i;
        x = j;
        break;
      }
    }
    if (y >= 0 || x >= 0) {
      break;
    }
  }

  fill_island(board, checked, y, x);

  bool ok = true;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board.at(i).at(j) == 'o') {
        if (!checked.at(i).at(j)) {
          ok = false;
        }
      }
    }
  }
  return ok;
}

bool can_make_one(vector<string> &board) {
  bool enabling = false;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      // 対象のマスが海である
      // 対象のマスが2つ以上の陸と隣接する
      // 対象のマスを海から陸に変えると、島を統一できるかどうか
      if (board.at(i).at(j) == 'x') {
        vector<string> board_copy = board;
        board_copy.at(i).at(j) = 'o';
        if (is_one_island(board_copy)) {
          enabling = true;
        }
      }
    }
  }
  return enabling;
}

int main() {
  int n = 10;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board.at(i);
  }
  // board[0] = "xxxxxxxxxx";
  // board[1] = "xoooooooxx";
  // board[2] = "xxoooooxxx";
  // board[3] = "xxxoooxxxx";
  // board[4] = "xxxxoxxxxx";
  // board[5] = "xxxxxxxxxx";
  // board[6] = "xxxxoxxxxx";
  // board[7] = "xxxoooxxxx";
  // board[8] = "xxoooooxxx";
  // board[9] = "xxxxxxxxxx";

  // 島が1つの場合
  if (is_one_island(board)) {
    cout << "YES" << endl;
    return 0;
  }
  // 島が複数の場合
  if (can_make_one(board)) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;
  return 0;
}
