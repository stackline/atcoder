#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int sum = 0;
  if (a <= k) {
    sum += a * 1;
    k -= a;
  } else {
    sum += k * 1;
    k -= k;
  }

  if (b <= k) {
    k -= b;
  } else {
    k -= k;
  }

  if (k > 0) {
    sum = sum - k;
  }

  cout << sum << endl;
  return 0;
}
