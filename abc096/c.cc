#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> v(H);
  for (int i = 0; i < H; i++) {
    cin >> v.at(i);
  }

  vector<int> dx{-1, 0, 1, 0};
  vector<int> dy{ 0, 1, 0, -1};

  bool can = true;
  for (int x = 0; x < H; x++) {
    for (int y = 0; y < W; y++) {
      char c = v.at(x).at(y);

      if (c == '.') { continue; }

      bool has_sharp = false;
      for (int i = 0; i < 4; i++) {
        int rx = x + dx.at(i);
        int ry = y + dy.at(i);

        if (rx >= 0 && rx < H && ry >= 0 && ry < W) {
          if (v.at(rx).at(ry) == '#') {
            has_sharp = true;
            break;
          }
        }
      }

      if (!has_sharp) {
        can = false;
      }
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
