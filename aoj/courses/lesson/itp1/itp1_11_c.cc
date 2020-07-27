#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dice {
  int top, bottom, front, back, left, right;
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
      top    = back;
      back   = bottom;
      bottom = front;
      front  = old_top;
    } else if (c == 'S') {
      top    = front;
      front  = bottom;
      bottom = back;
      back   = old_top;
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
};

int main() {
  // 1つ目のサイコロ
  vector<int> v1(6);
  for (int i = 0; i < 6; i++) {
    cin >> v1.at(i);
  }
  Dice dice1(v1);

  // 2つ目のサイコロ
  vector<int> v2(6);
  for (int i = 0; i < 6; i++) {
    cin >> v2.at(i);
  }
  Dice dice2(v2);

  bool matching = false;
  // サイコロ2を転がして、上面を1から6のラベルに変えていく
  // サイコロ2のそれぞれのラベルが上面になった状態で、
  // 前後左右からサイコロ2を見て、サイコロ1と比較する
  // top:1
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }
  // top:1 --> front:2
  dice2.roll('N');
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }
  // front:2 --> right:3
  dice2.roll('E');
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }
  // right:3 --> back:5
  dice2.roll('E');
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }
  // back:5 --> left:4
  dice2.roll('E');
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }
  // left:4 --> front:2 --> bottom:6
  dice2.roll('E');
  dice2.roll('N');
  if (dice1.matches_somewhere_in_4_directions(dice2)) {
    matching = true;
  }

  cout << (matching ? "Yes" : "No") << endl;
  return 0;
}
