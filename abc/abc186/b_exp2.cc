#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 空間計算量 O(1)
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w;
  cin >> h >> w;

  int sum = 0;
  int m = 100;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x;
      cin >> x;
      m = min(m, x);
      sum += x;
    }
  }

  cout << (sum - (h * w * m)) << endl;
  return 0;
}
