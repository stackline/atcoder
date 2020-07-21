#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;

  ll d = a / b;
  ll r = a % b;
  double f = (1.0 * a) / b;

  printf("%lld %lld %.5lf\n", d, r, f);
  return 0;
}
