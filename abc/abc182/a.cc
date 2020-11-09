#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b;
  cin >> a >> b;
  int c = 2 * a + 100;

  if (c > b) {
    cout << (c - b) << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
