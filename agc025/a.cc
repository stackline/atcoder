#include <bits/stdc++.h>
using namespace std;

int recursive(int num) {
  if (num < 10) {
    return num;
  }
  return recursive(num / 10) + (num % 10);
}

int main() {
  int N;
  cin >> N;

  int ans = 100000;
  for (int a = 1; a < N; a++) {
    int b = N - a;
    int sum = recursive(a) + recursive(b);
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
