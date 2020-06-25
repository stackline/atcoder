#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int M = max(max(A, B), C);

  int X = 0;
  if (M % 2 == (A + B + C) % 2) {
    X = M;
  } else {
    X = M + 1;
  }

  cout << ((3 * X - (A + B + C)) / 2) << endl;
  return 0;
}
