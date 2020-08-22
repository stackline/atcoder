#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int cnt = 0;
  for (int i = 0; i < 1000; i++) {
    // コンテナに各桁の数字をセットする
    vector<int> v(3);
    v.at(0) = i / 100;
    v.at(1) = (i/10) % 10;
    v.at(2) = i % 10;

    int v_index = 0;
    for (int j = 0; j < n; j++) {
      char c = '0' + v.at(v_index);
      if (s.at(j) == c) {
        v_index++;
        if (v_index == 3) {
          cnt++;
          break;
        }
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
