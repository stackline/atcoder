#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(n)
int main() {
  int n;
  cin >> n;

  // (d[1] + d[2] + ... + d[n])**2 = sigma(d[i]**2) + 2 * sigma(d[i] * d[j])
  //
  // 2 * sigma(d[i] * d[j]) = (d[1] + d[2] + ... + d[n])**2 - sigma(d[i]**2)
  // sigma(d[i] * d[j]) = ((d[1] + d[2] + ... + d[n])**2 - sigma(d[i]**2)) * (1/2)
  //
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    a += d;
    b += d*d;
  }

  int ans = ((a*a) - b) / 2;
  cout << ans << endl;
  return 0;
}
