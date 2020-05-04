#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> goods(n, true);

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector<int> from(m);
  vector<int> to(m);
  for (int i = 0; i < m; i++) {
    int left, right;
    cin >> left >> right;

    if (h[left - 1] < h[right - 1]) {
      goods[left - 1] = false;
    }
    if (h[left - 1] == h[right - 1]) {
      goods[left - 1] = false;
      goods[right - 1] = false;
    }
    if (h[left - 1] > h[right - 1]) {
      goods[right - 1] = false;
    }
  }

  int num = 0;
  for (int i = 0; i < n; i++) {
    if (goods[i] == true) { num++; }
  }
  cout << num << endl;
  return 0;
}
