#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> v(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v.at(i).at(j);
    }
  }

  int ans = 0;
  // 下に移動するタイミングが n パターンある
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += v.at(0).at(j);
    }
    for (int j = i; j < n; j++) {
      sum += v.at(1).at(j);
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
