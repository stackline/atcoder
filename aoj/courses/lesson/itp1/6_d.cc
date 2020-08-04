#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix.at(i).at(j);
    }
  }

  vector<int> column_vector(m);
  for (int i = 0; i < m; i++) {
    cin >> column_vector.at(i);
  }

  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = 0; j < m; j++) {
      ans += matrix.at(i).at(j) * column_vector.at(j);
    }
    cout << ans << endl;
  }

  return 0;
}
