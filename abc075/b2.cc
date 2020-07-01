#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w;

int bomb_count(vector<vector<char>> &v, int x, int y) {
  vector<pair<int, int>> points;
  points.push_back(make_pair(x - 1, y - 1));
  points.push_back(make_pair(x,     y - 1));
  points.push_back(make_pair(x + 1, y - 1));
  points.push_back(make_pair(x + 1, y));
  points.push_back(make_pair(x + 1, y + 1));
  points.push_back(make_pair(x,     y + 1));
  points.push_back(make_pair(x - 1, y + 1));
  points.push_back(make_pair(x - 1, y));

  int num = 0;
  for (auto point : points) {
    int xx = point.first;
    int yy = point.second;
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
