#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(N logN)
int main() {
  int N;
  cin >> N;

  vector<ll> v(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int max_multiple = N / i;
    for (int j = 1; j <= max_multiple; j++) {
      v.at(i * j)++;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += i * v.at(i);
  }

  cout << ans << endl;
  return 0;
}
