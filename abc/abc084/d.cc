#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(int n) {
  if (n < 2) { return false; } // 1 は素数ではない
  if (n == 2) { return true; } // 2 は素数である
  if (n % 2 == 0) { return false; } // 2 以外の偶数は素数ではない

  double square_root = sqrt(n);
  for (int i = 3; i <= square_root; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

bool is_similar_to_2017(int n) {
  bool cond1 = is_prime(n);
  bool cond2 = is_prime((n + 1) / 2);

  if (cond1 && cond2) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int Q;
  cin >> Q;

  const int lim = 100000;

  // 条件を満たす N のリストを用意
  vector<int> pm(lim, false);
  for (int i = 0; i < lim; i++) {
    pm.at(i) = is_similar_to_2017(i + 1);
  }

  // 累積和を用意
  vector<int> s(lim + 1, 0);
  for (int i = 0; i < lim; i++) {
    s.at(i + 1) = s.at(i) + pm.at(i);
  }

  for (int i = 0; i < Q; i++) {
    int left, right;
    cin >> left >> right;
    cout << (s.at(right) - s.at(left - 1)) << endl;
  }

  return 0;
}
