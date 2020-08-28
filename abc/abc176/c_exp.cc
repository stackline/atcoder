#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) { cin >> a.at(i); }

  ll ans = 0;
  int border = 0;
  for (int i = 0; i < n; i++) {
    border = max(border, a.at(i));
    ans += border - a.at(i);
  }

  cout << ans << endl;
  return 0;
}
