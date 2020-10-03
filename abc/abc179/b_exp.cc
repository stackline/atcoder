#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << "hogehoge" << '\n';  // "endl" executes flush in addition to line break.
int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> d.at(i).at(0);
    cin >> d.at(i).at(1);
  }

  for (int i = 0; i < n-2; i++) {
    bool a = d.at(i).at(0) == d.at(i).at(1);
    bool b = d.at(i+1).at(0) == d.at(i+1).at(1);
    bool c = d.at(i+2).at(0) == d.at(i+2).at(1);
    if (a && b && c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
