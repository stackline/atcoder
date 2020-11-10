#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i);
  }

  // i = 0 〜 n-1
  // j = 0 〜 i-1
  // k = 0 〜 j-1
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        int dx1 = x.at(j) - x.at(i);
        int dy1 = y.at(j) - y.at(i);
        int dx2 = x.at(k) - x.at(i);
        int dy2 = y.at(k) - y.at(i);
        // dy1 / dx1 = dy2 / dx2
        // --> dy1 * dx2 = dy2 * dx1
        if (dy1 * dx2 == dy2 * dx1) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
