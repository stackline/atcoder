#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> as(n, 0);
  vector<int> ps(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> as[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ps[i];
  }

  int ans = 0;
  for (int a : as) {
    for (int p : ps) {
      if ((a + p) == s) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
