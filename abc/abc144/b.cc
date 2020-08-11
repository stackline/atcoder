#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  bool can = false;
  for (int i = 1; i <= 9; i++) {
      for (int j = i; j <= 9; j++)
      {
          int product = i * j;
          if (product == n) {
              can = true;
          }
      }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
