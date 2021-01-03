#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  vector<double> x(n);
  vector<double> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
    cin >> y.at(i);
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double a = (y.at(j) - y.at(i)) / (x.at(j) - x.at(i));
      if (a >= -1 && a <= 1) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
