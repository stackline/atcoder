#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int x = (n + 1000 - 1) / 1000;
  int ans = x * 1000 - n;
  cout << ans << endl;
  return 0;
}
