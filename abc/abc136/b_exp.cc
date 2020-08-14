#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(int n) {
  int digit = 0;
  while (n) {
    n = n / 10;
    digit++;
  }

  return (digit % 2 == 1);
}

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (f(i)) { ans++; }
  }

  cout << ans << endl;
  return 0;
}
