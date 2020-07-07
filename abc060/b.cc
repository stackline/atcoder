#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  // 余りが 0 になる
  int lim = a * b;

  bool can = false;
  for (int i = 1; i <= lim; i++) {
    int d = a * i;
    if (d % b == c) {
      can = true;
      break;
    }
  }

  cout << (can ? "YES" : "NO") << endl;
  return 0;
}
