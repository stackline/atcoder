#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int combination(int n, int k) {
  int num = 1;
  for (int i = 1; i <= k; i++) {
    num = num * (n - i + 1) / i;
  }
  return num;
}
int main() {
  // 3C2
  int ans1 = combination(3, 2);
  cout << ans1 << endl;
  // --> 1 * (3 / 1) * (2 / 2)
  // --> 3

  // 10C4
  int ans2 = combination(10, 4);
  cout << ans2 << endl;
  // --> 1 * (10 / 1) * (9 / 2) * (8 / 3) * (7 / 4)
  // --> 210

  return 0;
}
