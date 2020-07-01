#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w;

int bomb_count(vector<vector<char>> &v, int x, int y) {
  vector<int> dx{ x - 1, x,     x + 1, x + 1, x + 1, x    , x - 1, x - 1 };
  vector<int> dy{ y - 1, y - 1, y - 1, y,     y + 1, y + 1, y + 1, y };

  int num = 0;
  for (int i = 0; i < 8; i++) {
    int xx = dx.at(i);
    int yy = dy.at(i);
    if (xx >= 0 && xx < h && yy >= 0 && yy < w) {
      if (v.at(xx).at(yy) == '#') {
        num++;
      }
    }
  }
  return num;
}

int main() {
  cin >> h >> w;

  vector<vector<char>> v(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> v.at(i).at(j);
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v.at(i).at(j) == '.') {
        cout << bomb_count(v, i, j);
      } else {
        cout << '#';
      }
    }
    cout << endl;
  }

  return 0;
}
