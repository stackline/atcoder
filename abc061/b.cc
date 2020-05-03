#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int from, to;
    cin >> from >> to;
    v[from]++;
    v[to]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << v[i] << endl;
  }
  return 0;
}
