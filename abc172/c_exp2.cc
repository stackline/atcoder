#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;

  vector<ll> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    a.at(i) = a.at(i - 1) + num;
  }

  vector<ll> b(m + 1, 0);
  for (int i = 1; i <= m; i++) {
    ll num;
    cin >> num;
    b.at(i) = b.at(i - 1) + num;
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (k < a.at(i)) {
      break;
    }
    ll limit = k - a.at(i);
    auto itr = upper_bound(b.begin(), b.end(), limit);
    int b_books = distance(b.begin(), itr) - 1;
    ans = max(ans, (i + b_books));
  }

  cout << ans << endl;
  return 0;
}
