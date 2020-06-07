#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 2
// 1 2 3 4 5 6
//
// 156 = 12
// 234 = 9
// ---
// 8
//
// 135 = 9
// 246 = 12
// ---
// 7
int main() {
  int N;
  cin >> N;

  vector<ll> a(N * 3);
  for (int i = 0; i < (N * 3); i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end(), greater<int>());

  ll ans = 0;
  for (int i = 0; i < (N * 2); i++) {
    if (i % 2 != 0) {
      ans += a.at(i);
    }
  }

  cout << ans << endl;
  return 0;
}
