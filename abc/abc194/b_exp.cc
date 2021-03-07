#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量: O(n**2)
// n <= 1000 より、最大 10**6 = 1_000_000
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a.at(i) >> b.at(i);
  }

  int ans = 200000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int time;
      if (i == j) {
        time = a.at(i) + b.at(j);
      } else {
        time = max(a.at(i), b.at(j));
      }
      ans = min(ans, time);
    }
  }

  cout << ans << endl;
  return 0;
}
