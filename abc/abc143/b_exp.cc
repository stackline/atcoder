#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 計算量 : O(n)
int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d.at(i);
  }

  // 累積和
  //
  //   s[0] = 0
  // i=0
  //   s[1] = s[0] + d[0]
  // i=1
  //   s[2] = s[1] + d[1]
  //
  vector<int> s(n+1, 0);
  for (int i = 0; i < n; i++) {
    s.at(i+1) = s.at(i) + d.at(i);
  }

  // i=0
  //   d[0] * (d[1] + d[2] + ... + d[n-1])
  // i=1
  //   d[1] * (d[2] + d[3] + ... + d[n-1])
  // i=n-2
  //   d[n-2] * (d[n-1])
  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    // 累積和から区間の合計を取る
    int dif = s.at(n) - s.at(i+1);
    ans += (d.at(i) * dif);
  }

  cout << ans << endl;
  return 0;
}
