#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  sort(v.rbegin(), v.rend());

  ll ans = 0;
  int t = n - 1;
  for (int i = 0; i < n; i++) {
    int lim = 2;
    if (i == 0) { lim = 1; }

    for (int j = 0; j < lim; j++) {
      if (t > 0) {
        ans += v.at(i);
        t--;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
