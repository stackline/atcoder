#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X;
  cin >> X;

  // 400-599 / 200 = 2
  // 600-799 / 200 = 3
  // ...
  // 1800-1999 / 200 = 9
  int kyu = 10 - X / 200;
  cout << kyu << endl;
  return 0;
}
