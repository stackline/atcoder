#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(N)
int main() {
  ll N;
  cin >> N;

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ll y = N / i;
    ll gx = (y * (y + 1) * i) / 2;
    ans += gx;
  }

  cout << ans << endl;
  return 0;
}
