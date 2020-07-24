#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    // m 中間
    // f 期末
    // r 再試験
    int m, f, r;
    cin >> m >> f >> r;

    if (m == -1 && f == -1 && r == -1) { break; }

    // 中間、期末のいずれかを欠席
    if (m == -1 || f == -1) {
      cout << "F" << endl;
    } else {
      int sum = 0;
      sum += (m >= 0 ? m : 0);
      sum += (f >= 0 ? f : 0);

      if (sum >= 80) {
        cout << "A" << endl;
      } else if (sum >= 65) {
        cout << "B" << endl;
      } else if (sum >= 50) {
        cout << "C" << endl;
      } else if (sum >= 30) {
        cout << (r >= 50 ? "C" : "D") << endl;
      } else {
        cout << "F" << endl;
      }
    }
  }
  return 0;
}
