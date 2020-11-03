#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  string s = "White";
  // 0 = 000
  // 1 = 001
  // 2 = 010
  // 3 = 011
  // 4 = 100
  // 5 = 101
  // 6 = 110
  // 7 = 111
  //
  // 例: n = 2 の場合
  //   010
  // & 001
  // -----
  //   000 = 0
  //
  // 例: n = 5 の場合
  //   101
  // & 001
  // -----
  //   001 = 1
  //
  if (n & 1) {
    s = "Black";
  }
  cout << s << endl;
  return 0;
}
