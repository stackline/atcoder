#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 10進数を8進数に変換する
// n: 10進数
string to_oct(int n) {
  string s;
  while (n > 0) {
    s = to_string(n % 8) + s;
    n = n / 8;
  }
  return s;
}

int main() {
  int a = 20;
  cout << to_oct(a) << endl; // 24

  //
  //  100 % 8 = 4
  //  100 / 8 = 12
  //
  //   12 % 8 = 4
  //   12 / 8 = 1
  //
  //    1 % 8 = 1
  //    1 / 8 = 0
  //
  // 10進数の 100 を 8 進数に変換すると 144 になる。
  //
  int b = 100;
  cout << to_oct(b) << endl; // 144
}
