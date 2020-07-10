#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  map<string, int> mp;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    if (mp.count(s) == 0) {
      mp.insert(make_pair(s, 1));
    } else {
      mp[s]++;
    }
  }

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;

    if (mp.count(s) == 0) {
      mp.insert(make_pair(s, -1));
    } else {
      mp[s]--;
    }
  }

  int ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    int n = itr->second;
    if (n > ans) {
      ans = n;
    }
  }

  cout << ans << endl;
  return 0;
}
