#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  ll ans = 1;
  bool overflow_flag = false;
  bool zero_flag = false;
  for (int i = 0; i < N; i++) {
    if (__int128(ans) * A.at(i) > __int128(1e18)) {
      overflow_flag = true;
    }
    if (A.at(i) == 0) {
      zero_flag = true;
    }

    ans = ans * A.at(i);
  }

  if (zero_flag) {
    cout << 0 << endl;
    return 0;
  }
  if (overflow_flag) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
