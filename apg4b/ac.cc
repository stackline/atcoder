#include <bits/stdc++.h>
using namespace std;

int main() {
  // 1 <= N <= 20
  int N, K;
  cin >> N >> K;

  vector<int> v(N, 0);
  // O(N) <= O(20)
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }

  bool existing = false;
  // O(2^N * N) <= O(2^20 * 20) <= O(20_971_520)
  // O(10^6) = O(1_000_000)
  // O(10^7) = O(10_000_000)
  // O(10^8) = O(100_000_000)
  for (int tmp = 0; tmp < (1 << 20); tmp++) {
    bitset<20> s(tmp);

    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        sum += v.at(i);
      }
    }
    if (sum == K) {
      existing = true;
      break;
    }
  }

  cout << (existing ? "YES" : "NO") << endl;
  return 0;
}
