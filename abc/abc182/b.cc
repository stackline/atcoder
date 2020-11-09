#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".
  int n;
  cin >> n;

  vector<int> a(n);
  int max_a = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    max_a = max(max_a, a.at(i));
  }

  int ans = 0;
  int max_cnt = 0;
  for (int i = 2; i <= max_a; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a.at(j) % i == 0) {
        cnt++;
      }
    }

    if (cnt >= max_cnt) {
      ans = i;
      max_cnt = cnt;
    }
  }

  cout << ans << endl;
  return 0;
}
