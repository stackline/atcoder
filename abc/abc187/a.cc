#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  string a, b;
  cin >> a >> b;

  int x = 0;
  int y = 0;
  for (int i = 0; i < 3; i++) {
    int ai = a.at(i) - '0';
    int bi = b.at(i) - '0';
    x += ai;
    y += bi;
  }

  if (x > y) {
    cout << x << endl;
  } else {
    cout << y << endl;
  }
  return 0;
}
