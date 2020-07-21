#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  while (1) {
    int h, w;
    cin >> h >> w;

    if (h == 0 && w == 0) { break; }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int sum = i + j;
        if (sum % 2 == 0) {
          cout << "#";
        } else {
          cout << ".";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
