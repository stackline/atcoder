#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  // 奇数マス空いている場合
  if ((B - A - 1) % 2 == 1) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }

  return 0;
}
