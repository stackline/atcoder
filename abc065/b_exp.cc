#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--; // 0-indexed
    v.at(i) = a;
  }

  int now = 0;
  int count = 0;
  while(1) {
    if (now == 1) {
      cout << count << endl;
      return 0;
    }
    if (count >= n) {
      cout << -1 << endl;
      return 0;
    }
    now = v.at(now);
    count++;
  }

  return 0;
}
