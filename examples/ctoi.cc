#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  throw invalid_argument("ctoi argument is not between '0' and '9'.");
}

int main() {
  int n = 1;
  char c = '1';

  cout << n + c << endl;
  // --> 50
  // 1 に '1' の数値表現である 49 を足す

  cout << n + ctoi(c) << endl;
  // --> 2

  return 0;
}
