#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int next = a[0];
  if (next == 2) {
    cout << 1 << endl;
    return 0;
  }

  int num = 1;
  for (int i = 0; i < n - 1; i++) {
    next = a[next - 1];
    num++;

    if (next == 2) {
      cout << num << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
