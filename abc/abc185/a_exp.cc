#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = min({a, b, c, d});
  cout << ans << endl;
  return 0;
}
