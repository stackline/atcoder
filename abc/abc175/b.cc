#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        ll a = v.at(i);
        ll b = v.at(j);
        ll c = v.at(k);
        // 3本の棒の長さは異なること
        if (a == b || a == c || b == c) { continue; }
        if ((a+b>c) && (b+c>a) && (c+a>b)) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
