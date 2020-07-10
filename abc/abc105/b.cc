#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int cake_max = N / 4;
  int donut_max = N / 7;

  bool enabling = false;
  for (int i = 0; i <= cake_max; i++) {
    for (int j = 0; j <= donut_max; j++) {
      int sum = 4 * i + 7 * j;
      if (sum == N) {
        enabling = true;
      }
    }
  }

  cout << (enabling ? "Yes" : "No") << endl;
  return 0;
}

