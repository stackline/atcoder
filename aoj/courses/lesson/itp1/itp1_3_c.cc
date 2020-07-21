#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, y;
  while (1) {
    cin >> x >> y;
    if (x == 0 && y == 0) { break; }

    int first, second;
    if (x < y) {
      first = x;
      second = y;
    } else {
      first = y;
      second = x;
    }
    cout << first << " " << second << endl;
  }
  return 0;
}
