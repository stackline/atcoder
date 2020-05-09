#include <bits/stdc++.h>
using namespace std;

bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int n = board.size();

  // 移動先がマス目の外
  if (x <= -1 || x >= n || y <= -1 || y >= n) {
    return false;
  }
  // 移動先が海
  if (board.at(x).at(y) == 'x') {
    return false;
  }
  // 移動先が調査済み
  if (checked.at(x).at(y) == true) {
    return false;
  }
  // それ以外
  return true;
}

bool reachable(vector<string> &board, vector<vector<bool>> &checked, int &island_num, int x, int y) {
  checked.at(x).at(y) = true;
  board.at(x).at(y) = '0' + island_num;

  if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, island_num, x - 1, y)) {
    return true;
  }
  if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, island_num, x, y + 1)) {
    return true;
  }
  if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, island_num, x + 1, y)) {
    return true;
  }
  if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, island_num, x, y - 1)) {
    return true;
  }
  // 未チェックの陸が無い時は終了
  return false;
}

int count_island(vector<string> &board, vector<vector<bool>> &checked) {
  int island_num = 0;
  int n = board.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 調査済みの場合
      if (checked.at(i).at(j) == true) {
        continue;
      }
      // 未調査の場合
      char object = board.at(i).at(j);
      // 海の場合
      if (object == 'x') {
        checked.at(i).at(j) = true;
        continue;
      }
      // 島の場合
      // 発見したら、十字に探索する
      // 探索しながら checked = true を増やす
      // 探索が終わった後、未探索の島が発見されたら、別の島とみなし
      // カウントアップを行う
      if (object == 'o') {
        island_num++;
        reachable(board, checked, island_num, i, j);
      }
    }
  }
  return island_num;
}

bool is_valid_ref(vector<string> &board, int x, int y) {
  int n = board.size();

  // 移動先がマス目の外
  if (x <= -1 || x >= n || y <= -1 || y >= n) {
    return false;
  }
  // 移動先が海
  if (board.at(x).at(y) == 'x') {
    return false;
  }
  // それ以外
  return true;
}

bool fillable(vector<string> &board, int &island_num, int x, int y) {
  vector<int> neighbors;
  if (is_valid_ref(board, x - 1, y)) {
    neighbors.push_back(board[x - 1][y]);
  }
  if (is_valid_ref(board, x, y + 1)) {
    neighbors.push_back(board[x][y + 1]);
  }
  if (is_valid_ref(board, x + 1, y)) {
    neighbors.push_back(board[x + 1][y]);
  }
  if (is_valid_ref(board, x, y - 1)) {
    neighbors.push_back(board[x][y - 1]);
  }

  auto result = unique(neighbors.begin(), neighbors.end());
  neighbors.erase(result, neighbors.end());

  return (island_num == (int)neighbors.size());
}

int main() {
  int n = 10;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board.at(i);
  }

  vector<vector<bool>> checked(n, vector<bool>(n, false));
  int island_num = count_island(board, checked);

  bool flag = false;
  if (island_num == 1) {
    flag = true;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (fillable(board, island_num, i, j)) {
          flag = true;
        }
      }
    }
  }

  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
