#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v.at(i);
  }

  int next = 1;
  int ans = 0;
  bool can = false;
  for (int i = 0; i < n; i++) {
    // ボタンをクリック
    next = v.at(next);
    ans++;
    if (next == 2) {
      can = true;
      break;
    }
  }

  cout << (can ? ans : -1) << endl;
  return 0;
}
