#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c;
  cin >> a >> b >> c;

  // c=1の場合、aoki 君のアメを1つ減らす
  // その上で、takahashi 君から操作を初めて、勝てるかどうかを判定する。
  if (a > (b - c)) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
