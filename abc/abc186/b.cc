#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w;
  cin >> h >> w;

  vector<int> a(101, 0);
  int minx = 100;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int n;
      cin >> n;
      minx = min(minx, n);
      a.at(n)++;
    }
  }
  int ans = 0;
  for (int i = minx + 1; i <= 100; i++) {
    int a_cnt = a.at(i);
    ans = ans + (i - minx) * a_cnt;
  }
  cout << ans << endl;
  return 0;
}
