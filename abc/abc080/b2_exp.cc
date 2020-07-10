#include <bits/stdc++.h>
using namespace std;

int recursive(int n) {
  if (n < 10) {
    return n;
  }
  return recursive(n / 10) + (n % 10);
}

int main() {
  int N;
  cin >> N;
  int num = recursive(N);
  cout << (N % num == 0 ? "Yes" : "No") << endl;
  return 0;
}
