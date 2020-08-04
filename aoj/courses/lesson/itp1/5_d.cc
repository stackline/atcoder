#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void call(int n) {
  for (int i = 1; i <= n; i++) {
    int x = i;
    // 3の倍数
    if (x % 3 == 0) {
      cout << " " << i;
    } else {
      // あるいは、いずれかの桁の数に3を含む
      while (x) {
        if (x % 10 == 3) {
          cout << " " << i;
          break;
        }
        x = x / 10;
      }
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  call(n);
  return 0;
}
