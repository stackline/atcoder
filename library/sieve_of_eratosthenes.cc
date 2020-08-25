#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// エラトステネスの篩
vector<bool> sieve_of_eratosthenes(vector<bool> is_prime) {
  int lim = (int)is_prime.size();

  for (int i = 2; i <= sqrt(lim); i++) {
    if (is_prime.at(i) == true) {
      for (int j = i * 2; j < lim; j = j + i) {
        is_prime.at(j) = false;
      }
    }
  }
  return is_prime;
}

int main() {
  int n = 101;
  vector<bool> is_prime(n, true);
  is_prime = sieve_of_eratosthenes(is_prime);

  vector<int> v{1, 2, 3, 4, 5, 13, 97, 99, 100};
  for (auto i : v) {
    cout << i << " is ";
    cout << (is_prime.at(i) ? "prime." : "not prime.");
    cout << endl;
  }

  return 0;
}
