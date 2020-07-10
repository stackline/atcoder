#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  //         a ------ b
  // c --- d
  //      c --- d
  //          c --- d
  //               c --- d
  //                    c --- d
  //      c ------------- d

  int ans = 0;
  // 時間帯が被っている場合
  if (b >= c && a <= d) {
    if (c <= a && d >= a && d <= b) {
      ans = d - a;
    } else if (c >= a && d <= b) {
      ans = d - c;
    } else if (c >= a && c <= b && d >= b) {
      ans = b - c;
    } else if (c <= a && d >= b) {
      ans = b - a;
    }
  }

  cout << ans << endl;
  return 0;
}
