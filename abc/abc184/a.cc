#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << (a * d - b * c) << endl;
  return 0;
}
