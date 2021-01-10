#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;
  ll ans = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
  }

  for (int i = 0; i < n; i++) {
    ans += a.at(i) * b.at(i);
  }

  if (ans == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
