#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, D;
  cin >> N >> D;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    if (x*x + y*y <= D*D) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
