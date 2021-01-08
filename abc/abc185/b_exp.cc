#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
  int n, m, t;
  cin >> n >> m >> t;

  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i) >> b.at(i);
  }

  int now = 0;
  int bat = n;

  for (int i = 0; i < m; i++) {
    bat -= a.at(i) - now;
    now = a.at(i);
    if (bat <= 0) {
      return false;
    }

    bat += b.at(i) - a.at(i);
    if (bat > n) {
      bat = n;
    }
    now = b.at(i);
  }

  // お店を出てから家に帰るまで
  bat -= t - now;
  if (bat <= 0) {
    return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}
