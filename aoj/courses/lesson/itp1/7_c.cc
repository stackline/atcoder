#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int r, c;
  cin >> r >> c;

  // データ受け取り
  vector<vector<int>> board(r + 1, vector<int>(c + 1));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board.at(i).at(j);
    }
  }

  // c列目に行の合計値を追加
  for (int i = 0; i < r; i++) {
    int sum = 0;
    for (int j = 0; j < c; j++) {
      sum += board.at(i).at(j);
    }
    board.at(i).at(c) = sum;
  }

  // r行目に列の合計値を追加
  for (int j = 0; j < c; j++) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
      sum += board.at(i).at(j);
    }
    board.at(r).at(j) = sum;
  }

  // 表全体の合計値を追加
  int sum = 0;
  for (int i = 0; i < r; i++) {
    sum += board.at(i).at(c);
  }
  board.at(r).at(c) = sum;

  // 表を出力する
  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c + 1; j++) {
      cout << board.at(i).at(j);
      // 最後の列の右に、スペースを表示しない
      if (j < c) { cout << " "; }
    }
    cout << endl;
  }
  return 0;
}
