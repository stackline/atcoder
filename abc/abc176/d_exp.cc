#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_valid_move(vector<string> &board, vector<vector<bool>> &checked, int h, int w) {
  int h_size = board.size();
  int w_size = board.at(0).size();

  // 移動先が表の外
  if (h <= -1 || h >= h_size || w <= -1 || w >= w_size) { return false; }
  // 移動先が壁
  if (board.at(h).at(w) == '#') { return false; }
  // 移動先が調査済み
  if (checked.at(h).at(w) == true) { return false; }
  // それ以外は移動可能
  return true;
}

bool walkable(vector<string> &board,
              vector<vector<bool>> &checked,
              vector<pair<int, int>> &reachable_list,
              int h,
              int w)
{
  // cout << "h, w: " << h << ", " << w << endl;
  checked.at(h).at(w) = true;
  reachable_list.push_back(make_pair(h, w));

  // ベースケース
  if (board.at(h).at(w) == 'g') {
    return true;
  }

  // 再帰ステップ
  // 上
  if (is_valid_move(board, checked, h-1, w)
      && walkable(board, checked, reachable_list, h-1, w)) { return true; }
  // 右
  if (is_valid_move(board, checked, h, w+1)
      && walkable(board, checked, reachable_list, h, w+1)) { return true; }
  // 下
  if (is_valid_move(board, checked, h+1, w)
      && walkable(board, checked, reachable_list, h+1, w)) { return true; }
  // 左
  if (is_valid_move(board, checked, h, w-1)
      && walkable(board, checked, reachable_list, h, w-1)) { return true; }

  return false;
}

void warpable(vector<string> &board,
              vector<vector<bool>> &checked,
              vector<pair<int, int>> &reachable_list,
              int h,
              int w)
{
  vector<int> dh{-2, -1, 0, 1, 2};
  vector<int> dw{-2, -1, 0, 1, 2};

  for (int i = 0; i < (int) dh.size(); i++) {
    for (int j = 0; j < (int) dw.size(); j++) {
      int next_h = h + dh.at(i);
      int next_w = w + dw.at(j);

      if (is_valid_move(board, checked, next_h, next_w)) {
        reachable_list.push_back(make_pair(next_h, next_w));
      }
    }
  }
}

int main() {
  int h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--; // 0-indexed

  // 入力受取
  vector<string> board(h);
  for (int i = 0; i < h; i++) { cin >> board.at(i); }
  // ゴールを g とする
  board.at(dh).at(dw) = 'g';
  // 移動情報の初期化
  vector<vector<bool>> checked(h, vector<bool>(w, false));

  int cost = 0;
  // コスト -1 で辿り着けるマス = スタート地点を列挙
  vector<pair<int, int>> reachable_list{make_pair(ch, cw)};

  while (1) {
    vector<pair<int, int>> dup = reachable_list;
    reachable_list = {};
    // コスト cost で辿り着けるマスを列挙
    for (pair<int, int> p : dup) {
      bool goal = walkable(board, checked, reachable_list, p.first, p.second);
      // ゴールを見つけた場合、その時点の cost がワープ利用の最小回数となる
      if (goal) {
        cout << cost << endl;
        return 0;
      }
    }

    // 徒歩でゴールが見つからなかった場合、ワープ先を探索する
    // コスト cost でたどり着いたマス reachable_list から、ワープ先を探す
    dup = reachable_list;
    reachable_list = {};
    for (pair<int, int> p : dup) {
      // ワープ先の候補を探すだけで、訪問は行わない
      warpable(board, checked, reachable_list, p.first, p.second);
    }

    // ワープ先の候補がない場合、徒歩でもワープでも到達不可能なため、探索をやめる
    if (reachable_list.size() == 0) { break; }

    // ワープ先の候補をユニークにしておく
    sort(reachable_list.begin(), reachable_list.end());
    auto itr = unique(reachable_list.begin(), reachable_list.end());
    reachable_list.erase(itr, reachable_list.end());

    // ワープ先をコスト +1 で探索する
    cost++;
  }

  cout << -1 << endl;
  return 0;
}
