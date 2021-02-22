#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int x;
  cin >> x;

  int next = x;
  while (true) {
    next++;
    if (next % 100 == 0) {
      cout << (next - x) << endl;
      return 0;
    }
  }

  return 0;
}
