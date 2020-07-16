#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int L, R, d;
  cin >> L >> R >> d;

  int r = R / d;
  int l = (L - 1) / d;
  cout << r - l << endl;
  return 0;
}
