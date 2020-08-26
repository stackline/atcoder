#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(vector<int> a, vector<int> b, int n) {
  for (int i = 0; i < n; i++) {
    if (a.at(i) != b.at(i)) {
      return false;
    }
  }
  return true;
}

// 計算量 : O(n! * n)
//
// irb> (1..8).to_a.permutation.count
// => 40320
//
int main() {
  int n;
  cin >> n;

  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> q.at(i);
  }

  // 大きさNの順列
  //
  // i element
  // ---------
  // 0 1
  // 1 2
  // 2 3
  //
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order.at(i) = i+1;
  }

  int cnt = 0;
  int p_number = 0;
  int q_number = 0;

  do {
    if (compare(order, p, n)) {
      p_number = cnt;
    }
    if (compare(order, q, n)) {
      q_number = cnt;
    }
    cnt++;
  } while (next_permutation(order.begin(), order.end()));

  cout << abs(p_number - q_number) << endl;
  return 0;
}
