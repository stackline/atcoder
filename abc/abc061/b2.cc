#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> v(N, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--; // 0-indexed

    v.at(a).at(b)++;
    v.at(b).at(a)++;
  }

  for (int i = 0; i < N; i++) {
    int ans = 0;
    for (int num : v.at(i)) {
      if (num > 0) {
        ans += num;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
