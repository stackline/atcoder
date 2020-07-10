#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for (int i = A; i <= B; i++) {
    int a = (i / 10000) % 10;
    int b = (i / 1000) % 10;
    int c = (i / 10) % 10;
    int d = (i / 1) % 10;
    if (a == d && b == c) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
