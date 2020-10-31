#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  int x = 0;
  int y = 20000;
  vector<int> downhill_point(40001, -1);
  downhill_point.at(y) = x;

  vector<int> areas(20001, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);
    x++;

    if (c == '\\') {
      y--;
      downhill_point.at(y) = x;
    } else if (c == '/') {
      y++;

      int downhill_x = downhill_point.at(y);
      // 標高 y から y-1 への下り坂が登場した後、標高 y-1 から y への上り坂が登場した場合、
      // 以下の面積が水たまりとなる。
      //
      //   (上り坂の終点の x 座標 - 下り坂の始点の x 座標 - 2) + 1
      //
      //   括弧内は長方形分の面積 (下り坂と上り坂を差し引いた、長方形エリアの水たまりの面積)
      //   +1 は長方向の左右の \ と / に 1/2 ずつ貯まる水たまりの和
      //
      // たとえば \_/ という文字列の場合、(4 - 1 - 2) + 1 = 1 + 1 = 2 となる。
      //
      //    \ _ /
      //   1 2 3 4
      //
      if (downhill_x >= 0) {
        int area = (x - downhill_x - 2) + 1;

        // 標高 y の水たまりを計算したとする。
        // 標高 y-1 の水たまりが存在した場合、標高 y に統合する。
        // なお、標高 y-1 の水たまりの範囲は標高 y より x 領域が狭くなる。
        //
        // ### 例
        // 標高 y の水たまりの x 座標は 1 から 4 である。
        // 標高 y-1 の水たまりの x 座標は 2 から 3 である。
        //
        //   y   \  /
        //   y-1  \/
        //       1234
        //
        // areas コンテナは水たまりの to の座標を起点に、水たまりの面積を管理する。
        //
        // 1. 標高 y-1 について、水たまりの面積を計算し、areas に登録する。
        //    areas[3] = 1
        // 2. 標高 y について、水たまりの面積を計算し、標高 y-1 の水たまりを加算した値を、areas に登録する。
        //
        //    標高 y の水たまりの x 座標の範囲が 1 から 4 であるため、
        //    x 座標が 2 から 3 の範囲に標高 y-1 以下の水たまりが存在するかを確認し、存在していれば加算する。
        //
        for (int i = downhill_x + 1; i <= (x - 1); i++) {
          if (areas.at(i) > 0) {
            area += areas.at(i);
            // 重複して加算しないように、加算し終わったら 0 でクリアする。
            areas.at(i) = 0;
          }
        }
        areas.at(x) = area;
        // cout << "x: " << x << ", area: " << areas.at(x) << endl;
      }

      // 標高 y について、直近に登場した x 座標の情報を元にした水たまりの計算が終わったため、
      // x 座標の情報を更新する。
      downhill_point.at(y) = x;
    } else if (c == '_') {
      downhill_point.at(y) = x;
    }
    // from-to の範囲と、水たまりの面積を管理する。
    // より広い範囲の水たまりが発生した場合、その水たまりが包含する狭い範囲の水たまりをマージする。
    // 以下のイメージ。
    // 1-12 が無い場合は、2つの水たまりが出来上がるイメージ。
    //
    //   1-------------12
    //    2---7 7----11
    //     3-5   8-10
  }

  int sum = 0;
  vector<int> ans;
  for (int i = 0; i <= (int)s.size(); i++) {
    // cout << "x: " << i << ", area: " << areas.at(i) << endl;
    int area = areas.at(i);
    if (area > 0) {
      sum += area;
      ans.push_back(area);
    }
  }

  cout << sum << endl;
  cout << ans.size();
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << " " << ans.at(i);
  }
  cout << endl;
  return 0;
}
