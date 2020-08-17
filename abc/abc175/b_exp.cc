#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        int x = v.at(i);
        int y = v.at(j);
        int z = v.at(k);
        if (x != y && y != z && z != x && (x+y) > z) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
