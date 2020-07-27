#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dice {
  int top, front, right, left, back, bottom;
  // constructor
  //
  //         top:1
  //           |
  // left:4--front:2--right:3--back:5
  //           |
  //         bottom:6
  //
  Dice(vector<int> v) {
    top    = v.at(0);
    front  = v.at(1);
    right  = v.at(2);
    left   = v.at(3);
    back   = v.at(4);
    bottom = v.at(5);
  }

  void roll(char c) {
    int old_top = top;
    if (c == 'E') {
      top    = left;
      left   = bottom;
      bottom = right;
      right  = old_top;
    } else if (c == 'N') {
      top    = front;
      front  = bottom;
      bottom = back;
      back   = old_top;
    } else if (c == 'S') {
      top    = back;
      back   = bottom;
      bottom = front;
      front  = old_top;
    } else if (c == 'W') {
      top    = right;
      right  = bottom;
      bottom = left;
      left   = old_top;
    }
  }

  // 1回、右回転させる
  // NOTE: ダイスを転がすわけではなく、見る位置を変える
  void rotate_front_surface() {
    int old_front = front;
    front = left;
    left = back;
    back = right;
    right = old_front;
  }

  bool operator==(Dice other) {
    if (top == other.top
        && front == other.front
        && right == other.right
        && left == other.left
        && back == other.back
        && bottom == other.bottom) {
      return true;
    } else {
      return false;
    }
  }

  // 表・裏・左・右の4方向から比較する
  bool matches_somewhere_in_4_directions(Dice other) {
    for (int i = 0; i < 4; i++) {
      other.rotate_front_surface();
      if (top == other.top
          && front == other.front
          && right == other.right
          && left == other.left
          && back == other.back
          && bottom == other.bottom)
      {
        return true;
      }
    }
    return false;
  }

  bool matches_somewhere_in_6_directions(Dice other) {
    bool matching = false;
    // サイコロ2を転がして、上面を1から6のラベルに変えていく
    // サイコロ2のそれぞれのラベルが上面になった状態で、
    // 前後左右からサイコロ2を見て、サイコロ1と比較する
    // top:1
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }
    // top:1 --> front:2
    other.roll('N');
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }
    // front:2 --> right:3
    other.roll('E');
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }
    // right:3 --> back:5
    other.roll('E');
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }
    // back:5 --> left:4
    other.roll('E');
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }
    // left:4 --> front:2 --> bottom:6
    other.roll('E');
    other.roll('N');
    if (matches_somewhere_in_4_directions(other)) {
      matching = true;
    }

    return matching;
  }
};

bool determine_if_unique(vector<Dice> dices) {
  int n = (int)dices.size();
  bool be_unique = true;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      Dice dice1 = dices.at(i);
      Dice dice2 = dices.at(j);

      if (dice1.matches_somewhere_in_6_directions(dice2)) {
        be_unique = false;
        break;
      }
    }
  }

  return be_unique;
}

int main() {
  int n;
  cin >> n;

  // サイコロを受け取る
  //
  // MEMO: 以下の書き方はできない
  //
  //   vector<Dice> dices(n);
  //
  // おそらくコンテナ格納時に、構造体から作成したオブジェクトをコンテナに格納する
  // この際、コンストラクタに引数が渡されないため、コンストラクタが存在せずコンパイルエラーとなると思われる
  vector<Dice> dices;

  for (int i = 0; i < n; i++) {
    vector<int> v(6);
    for (int j = 0; j < 6; j++) {
      cin >> v.at(j);
    }
    Dice dice(v);
    dices.push_back(dice);
  }

  bool is_unique = determine_if_unique(dices);
  cout << (is_unique ? "Yes" : "No") << endl;
  return 0;
}
