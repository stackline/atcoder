#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int i = 0; i <= n-3; i++) {
    string substring = s.substr(i, 3);
    if (substring == "ABC") {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
