#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, C;
  cin >> a >> b >> C;

  double radian = C * M_PI / 180;

  // ### 高さh
  // * sin(C) = h / b
  // * h = b * sin(C)
  double h = b * sin(radian);
  // ### 面積S
  // * S = 底辺 * 高さ * 1/2
  double S = a * h / 2;
  // 周の長さL
  // x**2 = h**2 + (a - b * cos(C))**2
  double square_x = (h * h) + (a * a) + (a * b * cos(radian) * -2) + (b * cos(radian) * b * cos(radian));
  double L = a + b + sqrt(square_x);

  printf("%.8f\n", S);
  printf("%.8f\n", L);
  printf("%.8f\n", h);
  return 0;
}
