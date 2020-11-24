#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'o') {
      x = x + 1;
    } else {
      x = max(x - 1, 0);
    }
  }

  cout << x << endl;
  return 0;
}
