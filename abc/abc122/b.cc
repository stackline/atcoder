#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_acgt(char c) {
  if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
    return true;
  } else {
    return false;
  }
}

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s.at(i);

    if (is_acgt(c)) {
      cnt++;
      ans = max(ans, cnt);
    } else {
      cnt = 0;
    }
  }

  cout << ans << endl;
  return 0;
}
