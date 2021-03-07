#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b;
  cin >> a >> b;

  if ((a + b) >= 15 && b >= 8) {
    // アイスクリーム
    cout << 1 << endl;
  } else if ((a + b) >= 10 && b >= 3) {
    // アイスミルク
    cout << 2 << endl;
  } else if ((a + b) >= 3) {
    // ラクトアイス
    cout << 3 << endl;
  } else {
    // 氷菓
    cout << 4 << endl;
  }
  return 0;
}
