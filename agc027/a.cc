#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int n = a.at(i);
    // お菓子が途中で足りなくなった場合
    if (x < n) {
      break;
    }
    // 最後の1名にお菓子を配る場合
    if (i == (N - 1)) {
      if (x == n) {
        ans++;
      }
      break;
    }

    x = x - a.at(i);
    ans++;
  }

  cout << ans << endl;
  return 0;
}
