#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int can = true;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    // 偶数について、3 or 5 のどちらでも割り切れないものがあるかどうか
    if (a % 2 == 0 && (a % 3 != 0 && a % 5 != 0)) {
      can = false;
    }
  }

  cout << (can ? "APPROVED" : "DENIED") << endl;
  return 0;
}
