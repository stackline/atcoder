#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); // Do not flush "cout" when processing "cin".

  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s.at(i);
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i < h - 1 && s.at(i).at(j) == '.' && s.at(i + 1).at(j) == '.') {
        ans++;
      }
      if (j < w - 1 && s.at(i).at(j) == '.' && s.at(i).at(j + 1) == '.') {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
