#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<pair<int, int>> point(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point.at(i) = make_pair(x, y);
  }

  // 点は最大100個
  // 100個のうち3個を選ぶ
  // 100C3 = (100 * 99 * 98) / (3 * 2 * 1) = 100 * 33 * 49 = 161700

  bool can = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        pair<int, int> a = point.at(i);
        pair<int, int> b = point.at(j);
        pair<int, int> c = point.at(k);

        int dx1 = b.first - a.first;
        int dx2 = c.first - a.first;
        int dy1 = b.second - a.second;
        int dy2 = c.second - a.second;

        if (dx2 * dy1 == dx1 * dy2) {
          can = true;
        }
      }
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
