#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == x) {
      continue;
    }
    if (i > 0) {
      cout << " ";
    }
    cout << a;
  }
  cout << endl;

  return 0;
}
