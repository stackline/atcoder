#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double h_angle = (360.0 / 12.0 * h) + (360.0 / 12.0 * m / 60.0);
  double m_angle = 360.0 / 60.0 * m;
  double angle   = abs(h_angle - m_angle);
  double radian  = angle * M_PI / 180.0;
  double ans = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radian));
  // cout << "M_PI    : " << M_PI << endl;
  // cout << "h_angle : " << h_angle << endl;
  // cout << "m_angle : " << m_angle << endl;
  // cout << "angle   : " << angle << endl;
  // cout << "radian  : " << radian << endl;
  // cout << "ans     : " << ans << endl;

  printf("%.10f\n", ans);
  return 0;
}
