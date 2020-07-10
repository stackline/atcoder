#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c.at(i).at(j);
    }
  }

  for (int i = 0; i <= c.at(0).at(0); i++) {
    vector<int> a(3);
    vector<int> b(3);

    a.at(0) = i;
    b.at(0) = c.at(0).at(0) - a.at(0);
    b.at(1) = c.at(0).at(1) - a.at(0);
    b.at(2) = c.at(0).at(2) - a.at(0);
    a.at(1) = c.at(1).at(0) - b.at(0);
    a.at(2) = c.at(2).at(0) - b.at(0);

    vector<pair<int, int>> vp;
    vp.push_back(make_pair(1, 1));
    vp.push_back(make_pair(1, 2));
    vp.push_back(make_pair(2, 1));
    vp.push_back(make_pair(2, 2));

    for (auto p : vp) {
      int ii = p.first;
      int jj = p.second;

      if (c.at(ii).at(jj) != (a.at(ii) + b.at(jj))) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
