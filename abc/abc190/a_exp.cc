#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int a, b, c;
  cin >> a >> b >> c;

  // C = 0 の場合
  //   A > B の場合 takahashi 君
  //   A = B の場合 aoki 君
  //   A < B の場合 aoki 君
  // C = 1 の場合
  //   A > B の場合 takahashi 君
  //   A = B の場合 takahashi 君
  //   A < B の場合 aoki 君
  //
  if (c == 0 && a > b) {
    cout << "Takahashi" << endl;
    return 0;
  }
  if (c == 1 && a >= b) {
    cout << "Takahashi" << endl;
    return 0;
  }
  cout << "Aoki" << endl;
  return 0;
}
