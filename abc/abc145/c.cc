#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(nPn * n) = O(n! * n)
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
  double sum = 0;
  int pattern = 0;
  do {
    for (int i = 1; i < n; i++) {
      pair<int, int> current = v.at(order.at(i-1));
      pair<int, int> next = v.at(order.at(i));

      int x1 = current.first;
      int y1 = current.second;
      int x2 = next.first;
      int y2 = next.second;

      int dist = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
      sum += sqrt(double(dist));
    }
    pattern++;
  } while (next_permutation(order.begin(), order.end()));

  double ans = sum / pattern;
  printf("%.10f\n", ans);
  return 0;
}
