#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }

  vector<string> v{"AC", "WA", "TLE", "RE"};
  for (auto s : v) {
    cout << s << " x " << mp[s] << endl;
  }
  return 0;
}
