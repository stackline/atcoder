#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (c % i == 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
