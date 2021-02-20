#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string s;
  cin >> s;

  bool ok = true;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);

    if ((i + 1) % 2 == 1) {
      // 奇数
      if (isupper(c)) {
        ok = false;
      }
    } else {
      // 偶数
      if (islower(c)) {
        ok = false;
      }
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
