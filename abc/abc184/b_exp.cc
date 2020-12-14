#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, x;
  string s;
  cin >> n >> x >> s;

  for (int i = 0; i < n; i++) {
    if (s.at(i) == 'o') {
      x++;
    } else {
      if (x >= 1) {
        x--;
      }
    }
  }

  cout << x << endl;
  return 0;
}
