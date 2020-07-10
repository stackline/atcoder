#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X, N;
  cin >> X >> N;

  map<int, bool> p;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    p[a] = true;
  }

  for (int i = 0; i < N + 1; i++) {
    int before = X - i;
    int after = X + i;

    if (p.count(before) == 0) {
      cout << before << endl;
      return 0;
    }
    if (p.count(after) == 0) {
      cout << after << endl;
      return 0;
    }
  }

  return 0;
}
