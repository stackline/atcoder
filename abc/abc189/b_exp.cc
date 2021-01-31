#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, x;
  cin >> n >> x;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int v, p;
    cin >> v >> p;
    sum += v * p;
    if (sum > x * 100) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
