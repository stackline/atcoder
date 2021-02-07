#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// cout << fixed << setprecision(15);
// printf("%.15f\n", sqrt(ans));
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
      // 黒マスの時に判定する
      if (s.at(i).at(j) == '#') {
        // 凸
        // 左上
        if (s.at(i - 1).at(j) == '.' && s.at(i).at(j - 1) == '.') {
          ans++;
        }
        // 右上
        if (s.at(i - 1).at(j) == '.' && s.at(i).at(j + 1) == '.') {
          ans++;
        }
        // 左下
        if (s.at(i + 1).at(j) == '.' && s.at(i).at(j - 1) == '.') {
          ans++;
        }
        // 右下
        if (s.at(i + 1).at(j) == '.' && s.at(i).at(j + 1) == '.') {
          ans++;
        }
        // 凹
        // 左上
        if (s.at(i).at(j - 1) == '#' && s.at(i - 1).at(j) == '#' &&
            s.at(i - 1).at(j - 1) == '.') {
          ans++;
        }
        // 右上
        if (s.at(i).at(j + 1) == '#' && s.at(i - 1).at(j) == '#' &&
            s.at(i - 1).at(j + 1) == '.') {
          ans++;
        }
        // 左下
        if (s.at(i).at(j - 1) == '#' && s.at(i + 1).at(j) == '#' &&
            s.at(i + 1).at(j - 1) == '.') {
          ans++;
        }
        // 右下
        if (s.at(i).at(j + 1) == '#' && s.at(i + 1).at(j) == '#' &&
            s.at(i + 1).at(j + 1) == '.') {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
