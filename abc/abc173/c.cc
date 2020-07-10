#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W, K;

vector<string> paint_row(vector<string> v, int h) {
  for (int i = 0; i < W; i++) {
    v.at(h).at(i) = '.';
  }
  return v;
}

vector<string> paint_column(vector<string> v, int w) {
  for (int i = 0; i < H; i++) {
    v.at(i).at(w) = '.';
  }
  return v;
}

int search_column(vector<string> v, int w) {
  // ベース処理
  if (w == W) {
    int sharp_count = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (v.at(i).at(j) == '#') {
          sharp_count++;
        }
      }
    }

    if (sharp_count == K) {
      return 1;
    } else {
      return 0;
    }
  }

  // w列目を塗る場合
  vector<string> v1 = v;
  v1 = paint_column(v1, w);
  int p1 = search_column(v1, w + 1);

  // w列目を塗らない場合
  vector<string> v2 = v;
  int p2 = search_column(v2, w + 1);

  return p1 + p2;
}

int search_row(vector<string> v, int h, int w) {
  // ベース処理
  if (h == H) {
    return search_column(v, w);
  }

  // 再帰処理
  // h行目を塗る場合
  vector<string> v1 = v;
  v1 = paint_row(v1, h);
  int p1 = search_row(v1, h + 1, w);

  // h行目を塗らない場合
  vector<string> v2 = v;
  int p2 = search_row(v2, h + 1, w);

  return p1 + p2;
}

int main() {
  cin >> H >> W >> K;

  vector<string> v;
  v.resize(H);
  for (int i = 0; i < H; i++) {
    cin >> v.at(i);
  }

  int ans = search_row(v, 0, 0);
  cout << ans << endl;
  return 0;
}
