#include <bits/stdc++.h>
using namespace std;

char itoc(int i) {
  if (i >= 0 && i <= 9) {
    return '0' + i;
  }
  throw invalid_argument("itoc argument is not between 0 and 9.");
}

int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  throw invalid_argument("ctoi argument is not between '0' and '9'.");
}

int main() {
  int a, b;
  cin >> a >> b;
  return 0;
}
