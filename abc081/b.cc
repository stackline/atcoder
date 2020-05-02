#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int A;
  cin >> A;
  int min = 0;
  while (A % 2 == 0) {
    A = A / 2;
    min++;
  }

  for (int i = 1; i < N; i++) {
    int B;
    cin >> B;

    int b_min = 0;
    while (B % 2 == 0) {
      B = B / 2;
      b_min++;
    }
    if (b_min < min) {
      min = b_min;
    }
  }
  cout << min << endl;
  return 0;
}
