#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int min_ab = min(a, b);

  for (int i = min_ab; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      k--;
      if (k == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}
