#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  vector<int> v(200005);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    v.at(p) = 1;
    while (v.at(ans) == 1) {
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
