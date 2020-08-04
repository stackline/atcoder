#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double a_square = (x2 - x1) * (x2 - x1);
  double b_square = (y2 - y1) * (y2 - y1);
  double c_square = a_square + b_square;

  double ans = sqrt(c_square);
  printf("%.5f\n", ans);
  return 0;
}
