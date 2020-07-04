#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  //         a ------ b
  // c --- d
  //      c --- d
  //          c --- d
  //               c --- d
  //                    c --- d
  //      c ------------- d

  int lower = max(a, c);
  int upper = min(b, d);

  cout << max(0, upper - lower) << endl;
  return 0;
}
