#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int count = 0;
  for (int i = a; i <= b; i++) {
    int q = i;

    int r1 = q % 10;
    q = q / 10;

    int r2 = q % 10;
    q = q / 10;

    // int r3 = q % 10;
    q = q / 10;

    int r4 = q % 10;
    q = q / 10;

    int r5 = q % 10;
    // q = q / 10;

    if (r1 == r5 && r2 == r4) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
