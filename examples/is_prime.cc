#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(int n) {
  if (n < 2) { return false; } // 1 は素数ではない
  if (n == 2) { return true; } // 2 は素数である
  if (n % 2 == 0) { return false; } // 2以外の偶数は素数ではない

  for (int i = 3; i <= sqrt(n); i = i + 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 13, 97, 99, 100};
  for (auto i : v) {
    cout << i << " is ";
    cout << (is_prime(i) ? "prime." : "not prime.");
    cout << endl;
  }
  return 0;
}
