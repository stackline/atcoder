#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n;
  cin >> n;

  int n2 = 1 << n;
  vector<int> a(n2);
  for (int i = 0; i < n2; i++) {
    cin >> a.at(i);
  }

  // キーはレート、値は選手の番号
  map<int, int> mp;
  for (int i = 0; i < n2; i++) {
    mp[a.at(i)] = i + 1;
  }

  while (a.size() > 2) {
    vector<int> b;
    for (int i = 0; i < (int)a.size(); i = i + 2) {
      int l = a.at(i);
      int r = a.at(i + 1);
      b.push_back(max(l, r));
    }
    swap(a, b);
  }

  cout << mp.at(min(a.at(0), a.at(1))) << endl;
  return 0;
}
