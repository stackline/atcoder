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

  for (int i = n - 1; i >= 0; i--) {
    cout << a.at(i);
    if (i != 0) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
