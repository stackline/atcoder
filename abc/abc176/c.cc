#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  ll sum = 0;
  int max = a.at(0);
  for (int i = 1; i < n; i++) {
    int current = a.at(i);

    if (current < max) {
      sum += max - current;
    } else if (current > max) {
      max = current;
    }
  }

  cout << sum << endl;
  return 0;
}
