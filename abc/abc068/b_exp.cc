#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; i < 8; i++) {
    int power = pow(2, i);
    if (power <= N) {
      ans = power;
    }
  }

  cout << ans << endl;
  return 0;
}
