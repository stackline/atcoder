#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  int ab_max = max(a, b);
  vector<int> v;
  for (int i = 1; i <= ab_max; i++) {
    if (a % i == 0 && b % i == 0) {
      v.push_back(i);
    }
  }

  reverse(v.begin(), v.end());

  cout << v.at(k-1) << endl;
  return 0;
}
