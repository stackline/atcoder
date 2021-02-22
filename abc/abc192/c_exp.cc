#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int g1(int x) {
  string s = to_string(x);
  sort(s.rbegin(), s.rend());
  return stoi(s);
}

int g2(int x) {
  string s = to_string(x);
  sort(s.begin(), s.end());
  return stoi(s);
}

int f(int x) {
  // cout << "x:     " << x << endl;
  // cout << "g1(x): " << g1(x) << endl;
  // cout << "g2(x): " << g2(x) << endl;
  return g1(x) - g2(x);
}

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int n, k;
  cin >> n >> k;

  int ax = n;
  for (int i = 0; i < k; i++) {
    ax = f(ax);
  }
  cout << ax << endl;
  return 0;
}
