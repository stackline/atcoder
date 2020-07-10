#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  for (int i = 0; i < N; i++) {
    cin >> l.at(i);
  }
  sort(l.begin(), l.end(), greater<int>());

  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += l.at(i);
  }

  cout << ans << endl;
  return 0;
}
