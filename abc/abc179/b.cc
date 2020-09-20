#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;

  int cnt = 0;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt == 3) {
      ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
