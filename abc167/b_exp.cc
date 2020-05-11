#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int xa = min(a, k);
  k -= xa;
  int xb = min(b, k);
  k -= xb;
  int xc = k;
  int ans = xa - xc;
  cout << ans << endl;
  return 0;
}
