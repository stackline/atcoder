#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < 3; ++i) {
    char c = s.at(i);
    if (c == 'R') {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 0;
    }
  }

  cout << ans << endl;
  return 0;
}
