#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  char op;
  while (1) {
    cin >> a >> op >> b;

    if (op == '+') {
      cout << a + b << endl;
    } else if (op == '-') {
      cout << a - b << endl;
    } else if (op == '*') {
      cout << a * b << endl;
    } else if (op == '/') {
      cout << a / b << endl;
    } else if (op == '?') {
      break;
    }
  }
  return 0;
}
