#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> point(N);

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    point.at(i) = make_pair(x, y);
  }

  double ans = 0;
  for (int i = 0; i < (N - 1); i++) {
    for (int j = (i + 1); j < N; j++) {
      pair<int, int> p1 = point.at(i);
      pair<int, int> p2 = point.at(j);

      int xx = pow((p2.first - p1.first), 2);
      int yy = pow((p2.second - p1.second), 2);
      double len = sqrt(xx + yy);
      ans = max(ans, len);
    }
  }

  printf("%.6f\n", ans);
  return 0;
}
