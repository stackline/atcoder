#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int m, h;
  cin >> m >> h;

  if (h % m == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
