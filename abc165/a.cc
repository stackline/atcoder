#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;

  bool flag = false;
  for (int i = a; i <= b; i++) {
    if (i % k == 0) {
      flag = true;
      break;
    }
  }

  if (flag) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
  return 0;
}
