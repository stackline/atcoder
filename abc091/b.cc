#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  map<string, int> mp;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    mp[t]--;
  }

  int max = 0;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    if (itr->second > max) {
      max = itr->second;
    }
  }

  cout << max << endl;
  return 0;
}
