#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(nPn * n) = O(n! * n)
//
//  N    O(N!N) O(N**2)
// --------------------
//  1         1       1
//  2         2       4
//  3         6       9
//  4        24      16
//  5       120      25
//  6       720      36
//  7      5040      49
//  8     40320      64
//  9    362880      81
// 10   3628800     100
// 11  39916800     121
// 12 479001600     144
//
int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.at(i) = make_pair(x, y);
  }

  // 初期順列
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order.at(i) = i;
  }

  // 順列全探索
  double sum = 0.0;
  int pattern = 0;
  do {
    for (int i = 1; i < n; i++) {
      pair<int, int> from = v.at(order.at(i-1));
      pair<int, int> to = v.at(order.at(i));

      double dx = to.first - from.first;
      double dy = to.second - from.second;
      double dist = sqrt(dx*dx + dy*dy);
      sum += dist;
    }
    pattern++;
  } while (next_permutation(order.begin(), order.end()));

  double ans = sum / pattern;
  printf("%.10f\n", ans);
  return 0;
}
