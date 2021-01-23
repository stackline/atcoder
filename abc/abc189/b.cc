#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  int x;
  cin >> n >> x;

  int x100 = x * 100;

  int cursor = -1;
  int mount = 0;
  int v, p;
  for (int i = 0; i < n; i++) {
    cin >> v >> p;
    mount += v * p;
    if (mount > x100) {
      cursor = i + 1;
      break;
    }
  }

  cout << cursor << endl;
  return 0;
}
