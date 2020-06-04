#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<int>());

  int slen = s.length();
  int tlen = t.length();

  int N = min(slen, tlen);

  bool enabling = false;
  for (int i = 0; i < N; i++) {
    if (s.at(i) < t.at(i)) {
      enabling = true;
      break;
    } else if (s.at(i) > t.at(i)) {
      enabling = false;
      break;
    }

    // 一方の文字列の末尾に到達した場合
    if (i == (N - 1)) {
      if (slen >= tlen) {
        enabling = false;
      } else {
        enabling = true;
      }
    }
  }

  cout << (enabling ? "Yes" : "No") << endl;
  return 0;
}
