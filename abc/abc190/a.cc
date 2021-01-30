#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c;
  cin >> a >> b >> c;

  while (1) {
    if (c == 0) {
      if (a == 0) {
        cout << "Aoki" << endl;
        return 0;
      }
      a--;
      c = 1;
    } else {
      if (b == 0) {
        cout << "Takahashi" << endl;
        return 0;
      }
      b--;
      c = 0;
    }
  }
  return 0;
}
