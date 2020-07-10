#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 700;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == 'o') {
      ans += 100;
    }
  }
  cout << ans << endl;
  return 0;
}
