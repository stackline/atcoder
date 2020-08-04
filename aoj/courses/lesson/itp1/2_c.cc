#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v{a, b, c};
  sort(v.begin(), v.end());

  cout << v.at(0) << " " << v.at(1) << " " << v.at(2) << endl;
  return 0;
}
