#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  for (int i = A; i <= B; i++) {
    string s = to_string(i);
    if (s.at(0) == s.at(4) && s.at(1) == s.at(3)) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
