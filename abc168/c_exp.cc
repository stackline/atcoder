#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double angle_h = (360.0 / 12.0 * h) + (360.0 / 12.0 * m / 60.0);
  double rad_h = angle_h * M_PI / 180;
  double xh = a * cos(rad_h);
  double yh = a * sin(rad_h);

  double angle_m = 360.0 / 60.0 * m;
  double rad_m = angle_m * M_PI / 180;
  double xm = b * cos(rad_m);
  double ym = b * sin(rad_m);
  double ans = sqrt(pow(xh - xm, 2) + pow(yh - ym, 2));

  printf("%.10f\n", ans);
  return 0;
}
