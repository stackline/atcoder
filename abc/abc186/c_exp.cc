#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string to_oct(int n) {
  string s;
  while (n > 0) {
    s = to_string(n % 8) + s;
    n = n / 8;
  }
  return s;
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (to_string(i).find("7") == string::npos &&
        to_oct(i).find("7") == string::npos) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
