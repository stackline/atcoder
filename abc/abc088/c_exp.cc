#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> v(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v.at(i).at(j);
    }
  }

  vector<int> x(3);
  vector<int> y(3);

  x.at(0) = 0;
  for (int i = 0; i < 3; i++) {
    y.at(i) = v.at(0).at(i) - x.at(0);
  }
  for (int i = 0; i < 3; i++) {
    x.at(i) = v.at(i).at(0) - y.at(0);
  }

  bool enabling = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (v.at(i).at(j) != (x.at(i) + y.at(j))) {
        enabling = false;
      }
    }
  }

  cout << (enabling ? "Yes" : "No") << endl;
  return 0;
}
