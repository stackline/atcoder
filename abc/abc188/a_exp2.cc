#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int x, y;
  cin >> x >> y;
  if (x > y) {
    swap(x, y);
  }
  if (x + 3 > y) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
