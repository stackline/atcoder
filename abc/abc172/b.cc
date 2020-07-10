#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S, T;
  cin >> S >> T;

  int ans = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    char s = S.at(i);
    char t = T.at(i);
    if (s != t) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
