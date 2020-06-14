#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X, Y;
  cin >> X >> Y;

  bool can = false;
  for (int i = 0; i <= X; i++) {
    int j = X - i;
    if ((i * 2 + j * 4) == Y) {
      can = true;
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
