#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  int x = 0;
  int y = 20000;
  // 各 y 座標について、最後に遷移した x 座標の位置を管理する。
  vector<int> v(40001, -1);
  v.at(y) = x;
  // 各 x 座標について、水たまりの面積を管理する。
  // 水たまり m が x 座標の xa から xb にかけて存在する場合、
  // puddles[xb] = m を登録する。つまり水たまりの終端の座標を基準として、面積を登録する。
  vector<int> puddles(20001, 0);

  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);

    // ポインタを次の座標に遷移させる
    x++;
    if (c == '\\') {
      y--;
    } else if (c == '_') {
      ;
    } else if (c == '/') {
      y++;
    }

    // "/" で y 座標が a から a+1 に移動する場合、
    // 事前に一度でも y 軸で a+1 の高さに移動したことがあれば、
    // a+1 を水面とした水たまりが発生する。
    // 一方で、一度も a+1 の高さに移動したことがなければ、水たまりは発生しない。
    int recent_x = v.at(y);
    if (c == '/' && recent_x >= 0) {
      // 高さ y についての水たまりの面積
      int area = (x - recent_x - 2) + 1;
      // 高さ y-1 に水たまりが存在する場合は、高さ y の水たまりに面積をまとめる。
      for (int i = (recent_x + 1); i <= (x - 1); i++) {
        if (puddles.at(i) > 0) {
          area += puddles.at(i);
          puddles.at(i) = 0;
        }
      }
      puddles.at(x) = area;
    }

    // 遷移後の「最後に遷移したx座標の位置」を管理する。
    v.at(y) = x;
  }

  int sum = 0;
  vector<int> ans;
  for (int i = 0; i <= (int)s.size(); i++) {
    int area = puddles.at(i);
    if (area > 0) {
      sum += area;
      ans.push_back(area);
    }
  }

  cout << sum << endl;
  cout << (int)ans.size();
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << " " << ans.at(i);
  }
  cout << endl;
  return 0;
}
