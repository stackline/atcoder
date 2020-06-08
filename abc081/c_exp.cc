#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  int N, K;
  cin >> N >> K;

  vector<int> cnt(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cnt.at(a - 1)++;
  }

  sort(cnt.begin(), cnt.begin() + N);

  int ans = 0;
  for (int i = 0; i < (N - K); i++) {
    ans += cnt.at(i);
  }

  cout << ans << endl;
  return 0;
}
