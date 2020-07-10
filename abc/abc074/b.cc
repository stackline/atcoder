#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    int a = x * 2;
    int b = (K - x) * 2;

    if (a < b) {
      sum += a;
    } else {
      sum += b;
    }
  }
  cout << sum << endl;
  return 0;
}
