#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;

  int less_than, lim;
  if (a < b) {
    less_than = a;
    lim = b;
  } else {
    less_than = b;
    lim = a;
  }

  for (int i = 0; i < lim; i++) {
    cout << less_than;
  }
  cout << endl;
  return 0;
}
