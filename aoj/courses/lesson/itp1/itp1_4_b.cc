#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  double r;
  cin >> r;

  double area = M_PI * r * r;
  double circumference = 2 * M_PI * r;
  printf("%f %f\n", area, circumference);
  return 0;
}
