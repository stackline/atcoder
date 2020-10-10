#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);               // Do not flush "cout" when processing "cin".
  // ios::sync_with_stdio(false); // Be careful when using both "cin/cout" and "scanf/printf".

  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s.at(i);
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w-1; j++) {
      // 横
      if (s.at(i).at(j) == '.' && s.at(i).at(j+1) == '.') {
        ans++;
      }
    }
  }
  for (int i = 0; i < h-1; i++) {
    for (int j = 0; j < w; j++) {
      // 縦
      if (s.at(i).at(j) == '.' && s.at(i+1).at(j) == '.') {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
