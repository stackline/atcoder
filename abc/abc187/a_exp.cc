#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int s) {
  int ret = 0;
  while (s > 0) {
    ret += s % 10;
    s /= 10;
  }
  return ret;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b;
  cin >> a >> b;
  int ans = max(f(a), f(b));
  cout << ans << endl;
  return 0;
}
