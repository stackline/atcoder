#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> v(H);
  for (int i = 0; i < H; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < H; i++) {
    string s = v[i];

    for (int j = 0; j < W; j++) {
      char c = v[i][j];

      if (c == '.') {
        int sum = 0;
        int i_next = i + 1;

        for (int k = i - 1; k <= i_next; k++) {
          if (k < 0 || k >= H) {
            continue;
          }
          int j_next = j + 1;

          for (int l = j - 1; l <= j_next; l++) {
            if (l < 0 || l >= W) {
              continue;
            }
            if (v[k][l] == '#') {
              sum++;
            }
          }
        }
        cout << sum;
      } else {
        cout << c;
      }
    }
    cout << endl;
  }
  return 0;
}
