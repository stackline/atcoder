#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;

  string L(b, '0'+a);
  string R(a, '0'+b);
  cout << min(L, R) << endl;
  return 0;
}
