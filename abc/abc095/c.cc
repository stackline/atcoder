#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(1) 定数時間
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  // ### 入力例
  // A 1円
  // B 1000円
  // C 500円
  //
  // C*2 = 1000円
  // A+B = 1001円
  int ans = 0;
  // A,Bを1枚ずつ買うより、ABを買う方が安い場合
  if ((c*2) < (a+b)) {
    // A,Bの少ない方のノルマを満たす枚数だけAB買う
    // これでA,Bのいずれかのノルマ or 同数の場合は両方のノルマが満たされる
    int ab_num = min(x, y) * 2;
    ans += c * ab_num;

    // 残りのノルマ
    x = x - (ab_num / 2);
    y = y - (ab_num / 2);

    // Aのノルマを満たした場合、Bを買い足す
    if (x == 0) {
      // Bを1枚買う方が安いか、ABを2枚買う方が安いか
      if (b < (c*2)) {
        ans += b * y;
      } else {
        ans += c * (y*2);
      }
    // Bのノルマを満たした場合、Aを買い足す
    } else {
      if (a < (c*2)) {
        ans += a * x;
      } else {
        ans += c * (x*2);
      }
    }
  // ABを買うより、A,Bを1枚ずつ買う方が安い場合
  } else {
    ans += a * x;
    ans += b * y;
  }

  cout << ans << endl;
  return 0;
}
