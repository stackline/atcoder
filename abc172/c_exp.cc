#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  ll K;
  cin >> N >> M >> K;

  // a0 = 0
  // a1 = a0 + A1
  // a2 = a1 + A2
  vector<ll> a(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    ll A;
    cin >> A;
    a.at(i) = a.at(i - 1) + A;
  }

  vector<ll> b(M + 1, 0);
  for (int i = 1; i <= M; i++) {
    ll B;
    cin >> B;
    b.at(i) = b.at(i - 1) + B;
  }

  // ai + bj <= K
  // bj <= K - aj
  int best = M;
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    ll a_num = a.at(i);

    if (a_num > K) { break; }

    for (int j = best; j >= 0; j--) {
      if (b.at(j) <= K - a_num) {
        best = j;
        break;
      }
    }

    ans = max(ans, (i + best));
  }

  cout << ans << endl;
  return 0;
}
