#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N; // <= 10^10

  int ans = 11;
  for (ll a = 1; a <= (sqrt(N) + 1); a++) {
    ll reminder = N % a;
    ll b = N / a;

    if (reminder != 0) {
      continue;
    }
    int len = max(to_string(a).size(), to_string(b).size());
    ans = min(ans, len);
  }

  cout << ans << endl;
  return 0;
}
