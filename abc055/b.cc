#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  ll divisor = 1000000007;
  ll power = 1;
  for (int i = 1; i <= n; i++) {
    // cout << power << " * " << i << " = ";
    power = power * i;
    if (power >= divisor) {
      power = power % divisor;
    }
    // cout << power << endl;
  }

  cout << power << endl;
  return 0;
}
