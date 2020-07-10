#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int less_than_1000 = n % 1000;
  int ans;
  if (less_than_1000 == 0) {
    ans = 0;
  } else {
    ans = 1000 - less_than_1000;
  }

  cout << ans << endl;
  return 0;
}
