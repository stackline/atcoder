#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(N + N + (N + 1) + (N + 1) + N)
// O(5N + 2)
// O(N)
int main() {
  int N;
  cin >> N;

  vector<int> A1(N);
  vector<int> A2(N);
  for (int i = 0; i < N; i++) {
    cin >> A1.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> A2.at(i);
  }

  // 行別の累積和
  vector<int> S1(N + 1, 0);
  vector<int> S2(N + 1, 0);
  for (int i = 0; i < N; i++) {
    S1.at(i + 1) = S1.at(i) + A1.at(i);
    S2.at(i + 1) = S2.at(i) + A2.at(i);
  }

  int ans = 0;
  // 下に移動するタイミング
  for (int j = 1; j <= N; j++) {
    int num = S1.at(j) + S2.at(N) - S2.at(j - 1);
    ans = max(ans, num);
  }

  cout << ans << endl;
  return 0;
}
